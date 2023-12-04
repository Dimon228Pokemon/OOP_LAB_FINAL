#pragma once
#include <iostream>
#include <memory>
#include <cstdlib>
template <typename T>
struct SNode
{
	T     _value;
	SNode* _next;

	SNode() : _next(this) {}
	SNode(const T& value): _value(value), _next(this) {}
};

template <typename T, typename _Alloc = std::allocator<T> >
struct Stack {

	using value_type = T;
	using size_type = std::size_t;
	using allocator_type = _Alloc;
	using node_t = SNode<T>;
	using node_pointer_t = SNode<T>*;
	using node_allocator_t = typename _Alloc::template rebind< node_t >::other;

public:
	Stack() :_head(nullptr), _size(0) {};

	void push(const value_type& value)
	{
		node_pointer_t temp = _node_allocator.allocate(1);
		_node_allocator.construct(temp, value);

		if (!temp) {
			std::cout << "\nStack Overflow";
			exit(1);
		}

		temp->_next = _head;
		_head = temp;
		_size++;
	}

	bool empty(){
		return _head == nullptr;
	}

	int top(){
		if (!empty()) return _head->_value;
		exit(1);
	}

	void pop()
	{
		node_pointer_t temp;

		if (empty()) {
			std::cout << "\nStack Underflow" << std::endl;
			exit(1);
		}
		else {
			temp = _head;
			_head = _head->_next;
			_node_allocator.destroy(temp);
			_node_allocator.deallocate(temp, 1);
			_size--;
		}
	}
	size_t size() {
		return _size;
	}

private:
	node_pointer_t      _head;
	size_t              _size;
	node_allocator_t    _node_allocator;
};