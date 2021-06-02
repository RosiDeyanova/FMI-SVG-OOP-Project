#include "Shape.h"
#include "Circle.h"

Shape::Shape()
{
	this->name = "none";
	this->x = 0;
	this->y = 0;
	strcpy_s(color, 5, "none");
}

Shape::~Shape()
{
	delete[] this->name;
	delete[] this->color;
}

Shape::Shape(const char* name, int x, int y, const char* color)
{
	this->name = name;
	this->x = x;
	this->y = y;
	strcpy_s(this->color, strlen(color) + 1, color);
}




