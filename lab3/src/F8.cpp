#include "F8.h"


std::istream& F8::inp(std::istream& input)
{
	std::cout << "Введите координаты вершин восьмиугольника." << std::endl;
	std::cout << "Координаты восьмиугольника вводите против часовой стрелки." << std::endl;

	for (size_t i = 0; i < _n; i++) {
		std::cout << "x" << std::to_string(i + 1) << " >>> " << std::endl;
		_p[i].x = this->inputNumber(input);
		std::cout << "y" << std::to_string(i + 1) << " >>> " << std::endl;
		_p[i].y = this->inputNumber(input);
	}

	return input;
}


std::ostream& F8::outp(std::ostream& output) const
{
	output << "Вершины восьмиугольника {";
	for (size_t i = 0; i < _n; i++) {
		if (i != 0) {
			output << ", ";
		}
		output << _p[i];
	}
	output << "}";
	return output;
}

Point F8::getCentr() const
{
	Point p0;
	for (size_t i = 0; i < _n; i++) {
		p0.x += _p[i].x / _n;
		p0.y += _p[i].y / _n;
	}
	return p0;
}

double F8::getSquare() const
{
	return (_n * ((_p[1].x - _p[0].x) * (_p[1].x - _p[0].x) +
		(_p[1].y - _p[0].y) * (_p[1].y - _p[0].y)) / 4) * (1.0 / tan(PI / _n));
}

size_t F8::getN() const {
	return _n;
}

std::string F8::getName() const {
	return _name;
}

F8::F8() {
	std::cout << "F8 def Construct" << std::endl;
}

F8::F8(double x1, double y1, double x2, double y2,
	double x3, double y3, double x4, double y4,
	double x5, double y5, double x6, double y6, 
	double x7, double y7, double x8, double y8) {
	_p[0].x = x1;
	_p[0].y = y1;
	_p[1].x = x2;
	_p[1].y = y2;
	_p[2].x = x3;
	_p[2].y = y3;
	_p[3].x = x4;
	_p[3].y = y4;
	_p[4].x = x5;
	_p[4].y = y5;
	_p[5].x = x6;
	_p[5].y = y6;
	_p[6].x = x7;
	_p[6].y = y7;
	_p[7].x = x8;
	_p[7].y = y8;
	std::cout << "F8 preset Construct" << std::endl;
}

F8::~F8()
{
	delete[] _p;
	std::cout << "F8 Destruct" << std::endl;
}

F8::F8(const F8& other)
{
	std::cout << "Copy constructor called to copy points " << std::endl;
	if (this != &other) {
		for (size_t i = 0; i < _n; i++) {
			_p[i].x = other._p[i].x;
			_p[i].y = other._p[i].y;
		}
	}
}

F8::F8(F8&& other) noexcept : _p(other._p)
{
	std::cout << "Move constructor called to move points " << std::endl;
	other._p = nullptr;
	other._n = 0;

}

F8& F8::operator=(const F8& right_operand)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &right_operand) {
		for (size_t i = 0; i < _n; i++) {
			_p[i].x = right_operand._p[i].x;
			_p[i].y = right_operand._p[i].y;
		}
	}
	return *this;
}

F8& F8::operator=(F8&& right_operand) noexcept
{
	std::cout << "Move assignment operator called" << std::endl;
	if (this != &right_operand) {
		delete[] _p;
		_p = right_operand._p;
		right_operand._p = nullptr;
		right_operand._n = 0;

	}
	return *this;
}
