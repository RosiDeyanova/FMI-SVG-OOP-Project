#pragma once
#include "Shape.h"
#include <cstring>
#include <iostream>

class Circle:public Shape
{
private:
	int r;

public:
	Circle();
	Circle(char* name, int x, int y, char* color, int r);
	void print() override;
	void setR(int r);
	int getR();


};

