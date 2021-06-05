#include "Rectangle.h"

Rectangle::Rectangle():Shape()
{
	delete[] this->name;
	this->name = new char[10];
	strcpy_s(this->name, 10, "rectangle");
	this->width = 0;
	this->height = 0;
	this->color = new char[6];
	strcpy_s(this->color, 5, "none");
}


void Rectangle::setWidth(int width)
{
	this->width = width;
}

void Rectangle::setHeight(int height)
{
	this->height = height;
}

Rectangle::Rectangle(char* name,int x,int y,int width, int height, char* color) :Shape(name,x, y, color) {
	delete[] this->name;
	this->name = new char[strlen(name)+1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->width = width;
	this->height = height;
	this->x = x;
	this->y = y;
	delete[] this->color;
	this->color = new char[strlen(color) + 1];
	strcpy_s(this->color, strlen(color) + 1, color);

}

void Rectangle::print() 
{
	std::cout << "rectangle " << this->x << " " << this->y << " " << this->width << " " << this->height << " "<< this->color << std::endl;
}
