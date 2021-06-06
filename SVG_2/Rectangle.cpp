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

int Rectangle::getWidth()
{
	return this->width;
}

int Rectangle::getHeight()
{
	return this->height;
}

Rectangle::Rectangle(char* name,int x,int y,int width, int height, char* color) :Shape(name,x, y, color) {
	this->width = width;
	this->height = height;
}

void Rectangle::print() 
{
	std::cout << "rectangle " << this->x << " " << this->y << " " << this->width << " " << this->height << " "<< this->color << std::endl;
}

void Rectangle::writeOut(std::ostream& out)
{
	out << "  <rectangle x=\"" << this->getX() << "\" y=\"" << this->getY() << "\" width=\"" << this->getWidth() << "\" height=\"" << this->getHeight() << "\"";
	out << " fill=\"" << this->getColor() << "\" />\n";

}
