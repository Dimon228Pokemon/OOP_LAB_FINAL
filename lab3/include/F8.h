#pragma once
#include "Figure.h"
class F8 :
    public Figure
{
public:
	//F8() = default;
	// базовый конструктор
	F8();
	// конструктор с пресетом
	F8(double x1, double y1, double x2, double y2,
		double x3, double y3, double x4, double y4,
		double x5, double y5, double x6, double y6, 
		double x7, double y7, double x8, double y8);
	// деструктор
	~F8();
	// конструктор копирования
	F8(const F8& other); // Copy constructor
	// конструктор присваивания
	F8(F8&& other) noexcept; // Move constructor

	// оператор копирования
	F8& operator= (const F8& right_operand);
	// оператор перемещения
	F8& operator= (F8&& right_operand) noexcept; // not const

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
	size_t _n{ 8 };
	// массив вершин фигуры вращения
	Point* _p = new Point[_n];
	std::string _name = "octagon";
};

