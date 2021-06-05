#include "Rectangle.h"

Rectangle::Rectangle():Shape()
{
	this->name = new char[6];
	strcpy_s(this->name, 5, "none");
	this->width = 0;
	this->height = 0;
}


void Rectangle::setName() 
{
	delete[] this->name;
	this->name = new char[10];
	strcpy_s(this->name, 10, "rectangle");
}

void Rectangle::setX(int x)
{
	this->x = x;
}

void Rectangle::setY(int y)
{
	this->y = y;
}

void Rectangle::setColor(char* color)
{
	this->color = color;
}

Rectangle::Rectangle(char* name,int x,int y,char* color,int width, int height) :Shape(name,x, y, color) {
	delete[] this->name;
	this->name = new char[strlen(name)+1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->width = width;
	this->height = height;

}

void Rectangle::print() 
{
	std::cout << "rectangle " << this->x << " " << this->y << " " << this->width << " " << this->height << " " << std::endl;
}
