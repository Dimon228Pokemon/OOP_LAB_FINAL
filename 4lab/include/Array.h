#pragma once
#include <iostream>
#include <memory>
#include "Figure.h"

template<typename TAF>
struct Array
{
	Array();
	~Array() = default;
	size_t size();
	void add(TAF* f);
	TAF* get(size_t index);
	void dell(size_t index);
	void show(size_t index);
	void showAll();
	int size_arr = 0;
	std::unique_ptr<TAF* []> ptr_arr = nullptr;
};


template<typename TAF>
inline Array<TAF>::Array() {
	ptr_arr = nullptr;
	size_arr = 0;
}

template<typename TAF>
inline size_t Array<TAF>::size() {
	return size_arr;
}


template<typename TAF>
inline void Array<TAF>::add(TAF* f) {
	if (this->size_arr > 0)
	{
		// создаем временный указатель умный и перемещаем туда содержимоего нашего массива
		std::unique_ptr<TAF* []> temp = std::move(ptr_arr);
		// увеличиваем счетчик
		size_arr += 1;
		// создаем новый массив умных указателей
		ptr_arr = std::make_unique<TAF * []>(size_arr);
		// переписываем все в новый из временного
		for (int i = 0; i < size_arr - 1; i++) {
			ptr_arr[i] = temp[i];
		}
		ptr_arr[size_arr - 1] = f;
	}
	else
	{
		size_arr = 1;
		ptr_arr = std::make_unique<TAF * []>(size_arr);;
		ptr_arr[0] = f;
	}
}

template<typename TAF>
inline TAF* Array<TAF>::get(size_t index) { return ptr_arr[index]; }

template<>
inline Figure<double>* Array<Figure<double>>::get(size_t index) { return ptr_arr[index]; }

template<typename TAF>
inline void Array<TAF>::dell(size_t index) {
	if (index < 0 or index >= size_arr) {
		return;
	}
	if (size_arr == 1) {
		// создаемвременный указатель умный и перемещаем туда содержимоего нашего массива
		std::unique_ptr<TAF* []> temp = std::move(ptr_arr);
		// обнуляем наш ptr_arr
		ptr_arr = nullptr;
		// обнуляем size_arr
		size_arr = 0;
	}
	else {
		// создаемвременный указатель умный и перемещаем туда содержимоего нашего массива
		std::unique_ptr<TAF* []> temp = std::move(ptr_arr);
		// новый счетчик
		size_t k = 0;
		// создаем новый массив умных указателей
		ptr_arr = std::make_unique<TAF * []>(size_arr - 1);
		// переписываем все в новый из временного
		for (size_t i = 0; i < size_arr; i++) {
			if (i == index) {
				continue;
			}
			ptr_arr[k] = temp[i];
			k++;
		}
		// уменьшаем size_arr
		size_arr--;
	}
}

template<typename TAF>
inline void Array<TAF>::show(size_t index) {
	if (index < 0 or index >= size_arr) {
		return;
	}
	std::cout << *ptr_arr[index] << std::endl;

}

template<>
inline void Array<Figure<double>>::show(size_t index) {
	if (index < 0 or index >= size_arr) {
		return;
	}
	std::cout << "--------------------------------- " << std::endl;
	std::cout << "Фигуры с индексом id           = " << (index + 1) << std::endl;
	std::cout << "Площадь фигуры                 = " << get(index)->getSquare() << std::endl;
	std::cout << "Координаты центра фигуры       = (" << get(index)->getCenter().first <<
		", " << get(index)->getCenter().second << ")" << std::endl;
	std::cout << "Координаты вершин фигуры :      " << std::endl << *ptr_arr[index] << std::endl;
}

template<typename TAF>
inline void Array<TAF>::showAll() {
	for (size_t i = 0; i < size_arr; i++) {
		show(i);
	}
}

template<>
inline void Array<Figure<double>>::showAll() {
	double s = 0;
	for (size_t i = 0; i < size_arr; i++) {
		show(i);
		s += get(i)->getSquare();
	}
	std::cout << "====================================" << std::endl;
	std::cout << "Суммарная площадь всех фигур = " << s << std::endl;
	std::cout << "====================================" << std::endl;
}