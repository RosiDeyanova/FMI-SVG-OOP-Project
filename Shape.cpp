#include "Shape.h"
#include "Circle.h"

Shape::Shape()
{
	this->x = 0;
	this->y = 0;
	this->color = new char[6];
	strcpy_s(color, 5, "none");
}

Shape::~Shape()
{
	delete[] this->name;
	delete[] this->color;
}

Shape::Shape(char* name, int x, int y, char* color)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->x = x;
	this->y = y;
	delete[] this->color;
	this->color = new char[strlen(color) + 1];
	strcpy_s(this->color, strlen(color) + 1, color);
}

void Shape::setX(int x)
{
	this->x = x;
}

void Shape::setY(int y)
{
	this->y = y;
}

void Shape::setColor(char* color)
{
	delete[] this->color;
	this->color = new char[strlen(color) + 1];
	strcpy_s(this->color, strlen(color) + 1, color);
}

int Shape::getX()
{
	return this->x;
}

int Shape::getY()
{
	return this->y;
}


