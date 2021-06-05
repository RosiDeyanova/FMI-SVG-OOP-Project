#pragma once
#include "Shape.h"
#include <cstring>
#include <iostream>

class Rectangle:public Shape
{
private:
	int width;
	int height;
public:
	Rectangle();
	Rectangle(char* name, int x, int y, int width, int height, char* color);
	void print() override;
	void setWidth(int width);
	void setHeight(int height);
};