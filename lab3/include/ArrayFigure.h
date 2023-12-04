#include "Figure.h"
class ArrayFigure
{
public:
	ArrayFigure();
	~ArrayFigure();
	void add(Figure* f);
	void del(size_t id);
	Figure* get(size_t id);
	void show(size_t id);
	void showAll();
	double getTotalSquare();

	//private:
	Figure** ptr_arr;
	size_t size_arr;
	double totalSquare;
};