#include "F3.h"


std::istream& F3::inp(std::istream& input)
{
	std::cout << "Введите координаты вершин треугольника." << std::endl;
	std::cout << "Координаты треугольника вводите против часовой стрелки." << std::endl;

	for (size_t i = 0; i < _n; i++) {
		std::cout << "x" << std::to_string(i + 1) << " >>> " << std::endl;
		_p[i].x = this->inputNumber(input);
		std::cout << "y" << std::to_string(i + 1) << " >>> " << std::endl;
		_p[i].y = this->inputNumber(input);
	}

	return input;
}


std::ostream& F3::outp(std::ostream& output) const
{
	output << "Вершины треугольника {";
	for (size_t i = 0; i < _n; i++) {
		if (i != 0) {
			output << ", ";
		}
		output << _p[i];
	}
	output << "}" ;
	return output;
}

Point F3::getCentr() const
{
	Point p0;
	for (size_t i = 0; i < _n; i++) {
		p0.x += _p[i].x / _n;
		p0.y += _p[i].y / _n;
	}
	return p0;
}

double F3::getSquare() const
{
	return (_n * ((_p[1].x - _p[0].x) * (_p[1].x - _p[0].x) +
		(_p[1].y - _p[0].y) * (_p[1].y - _p[0].y)) / 4) * (1.0 / tan(PI / _n));
}

size_t F3::getN() const{
	return _n;
}

std::string F3::getName() const{
	return _name;
}

F3::F3(){
	std::cout << "F3 def Construct" << std::endl;
}

F3::F3(double x1, double y1, double x2, double y2, double x3, double y3){
	_p[0].x = x1;
	_p[0].y = y1;
	_p[1].x = x2;
	_p[1].y = y2;
	_p[2].x = x3;
	_p[2].y = y3;
	std::cout << "F3 preset Construct" << std::endl;
}

F3::~F3()
{
	delete[] _p;
	std::cout << "F3 Destruct" << std::endl;
}

F3::F3(const F3& other)
{
	std::cout << "Copy constructor called to copy points " << std::endl;
	if (this != &other) {
		for (size_t i = 0; i < _n; i++){
			_p[i].x = other._p[i].x;
			_p[i].y = other._p[i].y;
		}
	}
}

F3::F3(F3&& other) noexcept : _p(other._p)
{
	std::cout << "Move constructor called to move points " << std::endl;
	other._p = nullptr;
	other._n = 0;

}

F3& F3::operator=(const F3& right_operand)
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

F3& F3::operator=(F3&& right_operand) noexcept
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
