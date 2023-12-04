#pragma once
#include "Figure.h"
class F6 : public Figure {
public:
	//F6() = default;
	// базовый конструктор
	F6();
	// конструктор с пресетом
	F6(double x1, double y1, double x2, double y2,
		double x3, double y3, double x4, double y4,
		double x5, double y5, double x6, double y6);
	// деструктор
	~F6();
	// конструктор копирования
	F6(const F6& other); // Copy constructor
	// конструктор присваивания
	F6(F6&& other) noexcept; // Move constructor

	// оператор копирования
	F6& operator= (const F6& right_operand);
	// оператор перемещения
	F6& operator= (F6&& right_operand) noexcept; // not const

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
	size_t _n{ 6 };
	// массив вершин фигуры вращения
	Point* _p = new Point[_n];
	std::string _name = "hexagon";
};

