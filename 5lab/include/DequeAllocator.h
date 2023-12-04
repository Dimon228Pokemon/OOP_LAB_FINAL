#pragma once
#include <iostream>
#include <deque>
#include <memory>
#include <cstdlib>
// -----------------------------------------------------------------------
//  DequeAllocator
// -----------------------------------------------------------------------

template <typename T, size_t HoldBlocks = 1>
class DequeAllocator
{
private:
	std::deque<void*> addrs_;
	std::deque<std::unique_ptr<uint8_t[]>> blocks_;
	size_t hb = HoldBlocks;
public:
	using value_type = T;
	using pointer = T*;
	using const_pointer = const T*;
	using size_type = std::size_t;

	DequeAllocator()
	{
		//std::cout << "HoldBlocks = " << HoldBlocks << std::endl;
		init();
	}

	~DequeAllocator() {}

	template <typename U>
	struct rebind
	{
		using other = DequeAllocator<U, HoldBlocks>;
	};

	T* allocate(size_t n)
	{
		T* result = nullptr;
		//std::cout << "allocate " << std::endl;
		if (addrs_.empty()) {
			//std::cout << "allocate addrs_.empty() -> init()" << std::endl;
			init();
		}
		result = (T*)addrs_.back();
		addrs_.pop_back();

		return result;
	}

	void deallocate(T* pointer, size_t)
	{
		//std::cout << "deallocate " << std::endl;
		addrs_.push_back(pointer);
	}

	template <typename U, typename... Args>
	void construct(U* p, Args &&...args)
	{
		//std::cout << "construct " << std::endl;
		new (p) U(std::forward<Args>(args)...);
	}

	void destroy(pointer p)
	{
		//std::cout << "destroy " << std::endl;
		p->~T();
	}
private:
	void init() {
		size_t BlockSize = sizeof(T) * (HoldBlocks + 1);
		auto block = std::make_unique<uint8_t[]>(BlockSize);
		for (size_t i = 0; i < BlockSize; i += sizeof(T)) {
			addrs_.push_back(&block.get()[i]);
		}
		blocks_.push_back(std::move(block));
	}
};

template <class T, class U>
constexpr bool operator==(const DequeAllocator<T>& lhs, const DequeAllocator<U>& rhs)
{
	return true;
}

template <typename T, typename U, size_t BLOCK_COUNT>
constexpr bool operator!=(const DequeAllocator<T>& lhs, const DequeAllocator<U>& rhs)
{
	return false;
}