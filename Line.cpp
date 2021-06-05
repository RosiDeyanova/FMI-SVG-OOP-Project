#include "Line.h"

Line::Line() :Shape()
{
	delete[] this->name;
	this->name = new char[5];
	strcpy_s(this->name, 5, "line");
	this->x2 = 0;
	this->y2 = 0;
	this->color = new char[6];
	strcpy_s(this->color, 5, "none");
}
Line::Line(char* name, int x, int y, char* color, int x2, int y2) : Shape(name,x, y,color) {
	this->x2 = x2;
	this->y2 = y2;

}
void Line::print()
{
	std::cout << "line " << this->x << " " << this->y << " " << this->x2 << " " << this->y2 << " "<<this->color << std::endl;
}

void Line::setX2(int x2)
{
	this->x2 = x2;
}

void Line::setY2(int y2)
{
	this->y2 = y2;
}
