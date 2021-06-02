#include "Rectangle.h"

Rectangle::Rectangle():Shape()
{
	this->name = "rectangle";
	this->width = 0;
	this->height = 0;
}


void Rectangle::setName() 
{
	this->name = "rectangle";
}

void Rectangle::setX(int x)
{
	this->x = x;
}

void Rectangle::setY(int y)
{
	this->y = y;
}

Rectangle::Rectangle(const char* name,int x,int y,char* color,int width, int height) :Shape(name,x, y, color) {
	this->name = name;
	this->width = width;
	this->height = height;

}

void Rectangle::print() 
{
	std::cout << "rectangle " << this->x << " " << this->y << " " << this->width << " " << this->height << " " << std::endl;
}
