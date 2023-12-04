// #define _ITERATOR_DEBUG_LEVEL 0

#include <iostream>
#include <map>
#include "Stack.h"
#include "DequeAllocator.h"
#include <stack>

static const int SZ = 10; // размер блоков памяти за раз

int factorial(int n) {
	int res = 1;
	for (int i = 1; i <= n; i++) {
		res *= i;
	}
	return res;
}


int main()
{
	{
		std::cout << "----------------------------------------" << std::endl;
		std::cout << "std::map" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		std::map<int, int> my_map;

		for (int i = 0; i < SZ; i++) {
			my_map[i] = factorial(i);
		}

		for (int i = 0; i < my_map.size(); i++) {
			std::cout << i << " " << my_map[i] << std::endl;
		}
	}
	{
		std::cout << "----------------------------------------" << std::endl;
		std::cout << "std::map DequeAllocator" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		std::map<int, int, std::less<int>, DequeAllocator< std::pair<const int, int>, SZ> > my_map;

		for (int i = 0; i < SZ; i++) {
			my_map[i] = factorial(i);
		}

		for (int i = 0; i < my_map.size(); i++) {
			std::cout << i << " " << my_map[i] << std::endl;
		}
	}

	{
		std::cout << "----------------------------------------" << std::endl;
		std::cout << " std::stack" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		std::stack<int> s;

		s.push(11);
		std::cout << "s.push(11)-> size = " << s.size() << " top = " << s.top() << std::endl;
		s.push(22);
		std::cout << "s.push(22)-> size = " << s.size() << " top = " << s.top() << std::endl;
		s.push(33);
		std::cout << "s.push(33)-> size = " << s.size() << " top = " << s.top() << std::endl;
		s.push(44);
		std::cout << "s.push(44)-> size = " << s.size() << " top = " << s.top() << std::endl;
		s.pop();
		std::cout << "s.pop()-> size = " << s.size() << " top = " << s.top() << std::endl;
		s.pop();
		std::cout << "s.pop()-> size = " << s.size() << " top = " << s.top() << std::endl;

	}
	{
		std::cout << "----------------------------------------" << std::endl;
		std::cout << "Stack std::Allocator" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		Stack<int> s;

		s.push(11);
		std::cout << "s.push(11)-> size = " << s.size() << " top = " << s.top() << std::endl;
		s.push(22);
		std::cout << "s.push(22)-> size = " << s.size() << " top = " << s.top() << std::endl;
		s.push(33);
		std::cout << "s.push(33)-> size = " << s.size() << " top = " << s.top() << std::endl;
		s.push(44);
		std::cout << "s.push(44)-> size = " << s.size() << " top = " << s.top() << std::endl;
		s.pop();
		std::cout << "s.pop()-> size = " << s.size() << " top = " << s.top() << std::endl;
		s.pop();
		std::cout << "s.pop()-> size = " << s.size() << " top = " << s.top() << std::endl;
		s.pop();
		std::cout << "s.pop()-> size = " << s.size() << " top = " << s.top() << std::endl;
	}
	{
		std::cout << "----------------------------------------" << std::endl;
		std::cout << "Stack DequeAllocator" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		Stack<int, DequeAllocator<int, 10>> s;

		s.push(11);
		std::cout << "s.push(11)-> size = " << s.size() << " top = " << s.top() << std::endl;
		s.push(22);
		std::cout << "s.push(22)-> size = " << s.size() << " top = " << s.top() << std::endl;
		s.push(33);
		std::cout << "s.push(33)-> size = " << s.size() << " top = " << s.top() << std::endl;
		s.push(44);
		std::cout << "s.push(44)-> size = " << s.size() << " top = " << s.top() << std::endl;
		s.pop();
		std::cout << "s.pop()-> size = " << s.size() << " top = " << s.top() << std::endl;
		s.pop();
		std::cout << "s.pop()-> size = " << s.size() << " top = " << s.top() << std::endl;
		s.pop();
		std::cout << "s.pop()-> size = " << s.size() << " top = " << s.top() << std::endl;
	}

	return 0;
}
