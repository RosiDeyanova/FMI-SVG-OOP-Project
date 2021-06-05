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
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->r= r;
	this->x = x;
	this->y = y;
	delete[] this->color;
	this->color = new char[strlen(color) + 1];
	strcpy_s(this->color, strlen(color) + 1, color);
}
void Circle::print()
{
	std::cout << "circle " << this->x << " " << this->y << " " << this->r << " " << this->color<< std::endl;
}

void Circle::setR(int r)
{
	this->r = r;
}
