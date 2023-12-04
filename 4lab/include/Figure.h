#pragma once
#include <iostream>
#include <memory>
#include <utility>
#include <initializer_list>
#include <cmath>
#define PI 3.14159265 

template<typename T>
struct Figure {

	T getSquare();

	explicit operator double();

	std::pair<T, T> getCenter();

	//virtual void setS(const std::initializer_list<std::pair<T, T>>& il);
	virtual void setPoints(const std::initializer_list<std::pair<T, T>>& il);

	template <typename U>
	friend std::ostream& operator<<(std::ostream& output, const Figure<U>& f);

	template <typename U>
	friend std::istream& operator>>(std::istream& is, Figure<U>& f);

	bool operator==(Figure<T>& f);

	Figure<T>& operator= (const Figure<T>& right_operand);

	size_t nn;
	virtual ~Figure() = default;
protected:
	Figure() = default;


	std::pair<T, T>* getPoints(Figure<T>& f);
};

template<typename T>
struct Triangle :Figure<T> {
	std::pair<T, T> points[3];
};

template<typename T>
struct Hexagon :Figure<T> {
	std::pair<T, T> points[6];
};
//
template<typename T>
struct Octagon :Figure<T> {
	std::pair<T, T> points[8];
};

template<typename U>
inline std::ostream& operator<<(std::ostream& output, const Figure<U>& f) {
	auto& ff = const_cast<Figure<U>&>(f);
	std::pair<U, U>* pp = ff.getPoints(ff);
	output << "Points { ";
	for (size_t i = 0; i < ff.nn; i++) {
		output << " (" << pp[i].first << ", " << pp[i].second << "),";
	}
	output << "\b \b }";
	return output;
}

template<typename U>
inline std::istream& operator>>(std::istream& ismy, Figure<U>& f) {
	std::pair<U, U>* pp = f.getPoints(f);
	for (size_t i = 0; i < f.nn; i++) {
		std::cout << "x" << (i + 1) << " = "; ismy >> pp[i].first;
		std::cout << "y" << (i + 1) << " = "; ismy >> pp[i].second;
	}
	return ismy;
}

template<typename T>
inline T Figure<T>::getSquare() {
	T l = 0.0;
	std::pair<T, T>* pp = getPoints(*this);
	l = pow((pp[0].first - pp[1].first), 2) + pow((pp[0].second - pp[1].second), 2);
	return (nn * l / 4) * (1.0 / tan(PI / nn));
}

template<typename T>
inline Figure<T>::operator double() {
	return (static_cast <double> (getSquare()));
}


template<typename T>
inline std::pair<T, T> Figure<T>::getCenter() {
	std::pair<T, T> p0{ 0.0, 0.0 };
	std::pair<T, T>* pp = getPoints(*this);
	for (size_t i = 0; i < nn; i++) {
		p0.first += pp[i].first / nn;
		p0.second += pp[i].second / nn;
	}
	return p0;
}

template<typename T>
inline bool Figure<T>::operator==(Figure<T>& ff)
{
	if (nn == ff.nn && ff.getSquare() == getSquare()) {
		return true;
	}
	return false;
}

template<typename T>
inline Figure<T>& Figure<T>::operator=(const Figure<T>& right_operand) {
	std::cout << "Copy assignment operator called" << std::endl;
	auto& fR = const_cast<Figure<T>&>(right_operand);
	std::pair<T, T>* ppL = getPoints(*this);
	std::pair<T, T>* ppR = fR.getPoints(fR);
	if (this != &right_operand) {
		for (size_t i = 0; i < nn; i++) {
			ppL[i] = ppR[i];
		}
	}
	return *this;
}

template<typename T>
inline void Figure<T>::setPoints(const std::initializer_list<std::pair<T, T>>& il)
{
	std::pair<T, T>* pp = getPoints(*this);
	size_t i = 0;
	for (auto p : il) {
		pp[i] = p; 
		i++;
		if (i == nn) { return; }
	}
}

template<typename T>
inline std::pair<T, T>* Figure<T>::getPoints(Figure<T>& f)
{
	if (Triangle<T>* child = dynamic_cast<Triangle<T>*>(&f)) { nn = 3;  return child->points; }
	else if (Hexagon<T>* child = dynamic_cast<Hexagon<T>*>(&f)) { nn = 6;  return child->points; }
	else if (Octagon<T>* child = dynamic_cast<Octagon<T>*>(&f)) { nn = 8;  return child->points; }
	return nullptr;
}
