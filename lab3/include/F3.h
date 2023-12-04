#pragma once
#include "Figure.h"

class F3 :
	public Figure
{
public:
	//F3() = default;
	// базовый конструктор
	F3();
	// конструктор с пресетом
	F3(double x1, double y1, double x2, double y2, double x3, double y3);
	// деструктор
	~F3();
	// конструктор копирования
	F3(const F3& other); // Copy constructor
	// конструктор присваивания
	F3(F3&& other) noexcept; // Move constructor

	// оператор копирования
	F3& operator= (const F3& right_operand); 
	// оператор перемещения
	F3& operator= (F3&& right_operand) noexcept; // not const

	// возвращает поток ввода
	std::istream& inp(std::istream& input)  override;
	// возвращает поток вывода
	std::ostream& outp(std::ostream& output)  const override;
	// возвращаем точку центра вращения
	Point getCentr() const override;
	// возвращает площадь фигуры
	double getSquare() const override;
	// возвращаем число вершин фигуры вращения
	size_t getN() const override;
	
	// возвращаем имя объекта
	std::string getName() const override;

	// число вершин фигуры вращения
	size_t _n{ 3 }; 
	// массив вершин фигуры вращения
	Point* _p = new Point[_n];
	std::string _name = "triangle";

};