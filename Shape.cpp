#include "Shape.h"

Shape::Shape()
{
	this->x = 0;
	this->y = 0;
	strcpy_s(stroke, 5, "none");
	this->strokeWidth = 0;
}

Shape::Shape(int x, int y, const char* stroke, int strokeWidth)
{
	this->x = x;
	this->y = y;
	strcpy_s(this->stroke, strlen(stroke) + 1, stroke);
	this->strokeWidth = strokeWidth;
}
