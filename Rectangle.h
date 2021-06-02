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
	Rectangle(const char* name, int x, int y, char* color, int width, int height);
	void print() override;
	void setName() override;
	void setX(int x) override;
	void setY(int y) override;
};

