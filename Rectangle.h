#pragma once
#include "Shape.h"
#include <cstring>
#include <iostream>

class Rectangle:public Shape
{
private:
	int width;
	int height;
	char fill[10];
public:
	Rectangle();
	Rectangle(int width, int height, const char* fill);
	void print();
};

