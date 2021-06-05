#include "Circle.h"

Circle::Circle() :Shape()
{
	delete[] this->name;
	this->name = new char[10];
	strcpy_s(this->name, 10, "circle");
	this->r = 0;
	this->color = new char[6];
	strcpy_s(this->color, 5, "none");
}

Circle::Circle(char* name,int x, int y,char* color, int r) : Shape(name,x, y, color) {
	this->r= r;
}
void Circle::print()
{
	std::cout << "circle " << this->x << " " << this->y << " " << this->r << " " << this->color<< std::endl;
}

void Circle::setR(int r)
{
	this->r = r;
}

int Circle::getR()
{
	return this->r;
}
