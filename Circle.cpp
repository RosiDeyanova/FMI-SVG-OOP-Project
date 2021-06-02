#include "Circle.h"

Circle::Circle() :Shape()
{
	this->r = 0;
}

Circle::Circle(char* name,int x, int y,char* color, int r) : Shape(name,x, y, color) {
	this->r = r;
}
void Circle::print()
{
	std::cout << "circle " << this->x << " " << this->y << " " << this->r << " " << std::endl;
}