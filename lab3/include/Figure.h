#pragma once
#include <iostream>
#include <string>
#include <regex>
#include <cmath> 
#include "Point.h"
#define PI 3.14159265 



class Figure
{
	friend std::ostream& operator<<(std::ostream& os, const Figure& f);
	friend std::istream& operator>>(std::istream& is, Figure& f);
public:
	virtual ~Figure() = default; // If destructor is not public, you won't be
	// able to delete base_ptrs. SHOW THIS TO STUDENTS
	
	// возвращает поток ввода
	virtual std::istream& inp(std::istream& input) = 0;
	// возвращает поток вывода
	virtual std::ostream& outp(std::ostream& output) const = 0;
	// возвращает координаты {x,y} центра фигуры 
	virtual Point getCentr() const = 0;
	// возвращает площадь фигуры
	virtual double getSquare() const = 0;
	// переопределение приведения типа
	explicit operator double() const;
	// переопределяем оператор равенства фигур
	bool operator==(const Figure& f);
	// взовращаем имя объекта
	virtual std::string getName() const = 0;

protected:
	Figure() = default;

	// возвращаем количество сторон фигуры
	virtual size_t getN() const = 0;
	// метод ввода с валидацией чисел на вводе
	double inputNumber(std::istream& input);
};
