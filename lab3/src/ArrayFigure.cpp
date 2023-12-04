//#include "../include/ArrayFigure.h"
#include "ArrayFigure.h"

ArrayFigure::ArrayFigure()
{
	this->ptr_arr = nullptr;
	this->size_arr = 0;
	this->totalSquare = 0;
}

ArrayFigure::~ArrayFigure()
{
	for (size_t i = 0; i < this->size_arr; i++) {
		delete this->ptr_arr[i];
	}
	delete[] this->ptr_arr;
}


void ArrayFigure::add(Figure* fig) {
	// смотрим на размер нашего массива
	if (this->size_arr > 0)
	{
		Figure** temp = new Figure * [this->size_arr];
		memcpy(temp, this->ptr_arr, this->size_arr * sizeof(Figure*));
		delete[]this->ptr_arr;
		this->size_arr += 1;
		this->ptr_arr = new Figure * [this->size_arr];
		memcpy(this->ptr_arr, temp, (this->size_arr - 1) * sizeof(Figure*));
		this->ptr_arr[this->size_arr - 1] = fig;
	}
	else
	{
		this->size_arr = 1;
		this->ptr_arr = new Figure * [this->size_arr];
		this->ptr_arr[0] = fig;
	}
	this->totalSquare += fig->getSquare();
}


void ArrayFigure::del(size_t id)
{
	size_t k = 0;

	if (this->size_arr == 0 or id >= this->size_arr) {
		throw "no elements in array";
	}
	this->totalSquare -= this->ptr_arr[id]->getSquare();
	Figure** ptr_tmp;
	// временно перенесли все в новое место
	ptr_tmp = new Figure * [this->size_arr];
	memcpy(ptr_tmp, this->ptr_arr, sizeof(Figure*) * this->size_arr);

	// удалили старый массив
	delete[] this->ptr_arr;

	// уменьшили размер
	this->size_arr--;
	// создали новый увеличенный
	this->ptr_arr = new Figure * [this->size_arr];
	for (size_t i = 0; i < this->size_arr + 1; i++) {
		if (i == id) {
			delete ptr_tmp[i];
			continue;
		}
		this->ptr_arr[k] = ptr_tmp[i];
		k++;
	}
	// удалили указатель на временных массив
	delete[] ptr_tmp;
}

Figure* ArrayFigure::get(size_t id)
{
	if (id<0 or id>this->size_arr) {
		throw "Error, figure not found\n";
	}
	return this->ptr_arr[id];
}

void ArrayFigure::show(size_t id)
{
	if (id<0 or id>this->size_arr) {
		throw "Error, figure not found\n";
	}
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "Фигуры с индексом id=" << id << std::endl;
	std::cout << "Тип фигуры: " << this->ptr_arr[id]->getName() << std::endl;
	std::cout << "Площадь фигуры: " << this->ptr_arr[id]->getSquare() << std::endl;
	std::cout << "Координаты центра фигуры: " << this->ptr_arr[id]->getCentr() <<  std::endl;
	std::cout << "Координаты вершин фигуры: " << std::endl << *this->ptr_arr[id] << std::endl;
}

void ArrayFigure::showAll()
{
	std::cout << "==================================================" << std::endl;
	std::cout << "Колво фигур в массиве: " << this->size_arr << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	for (size_t i = 0; i < this->size_arr; i++) {
		this->show(i);
	}
	std::cout << "==================================================" << std::endl;
	std::cout << "Общая площадь фигур: " << this->totalSquare << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
}

double ArrayFigure::getTotalSquare()
{
	return this->totalSquare;
}



