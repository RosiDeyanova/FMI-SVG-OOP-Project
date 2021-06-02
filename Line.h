#pragma once
#include "Shape.h"
#include <cstring>
#include <iostream>

class Line:public Shape
{
private:
	int x2;
	int y2;
public:
	Line();
	Line(char* name, int x, int y, char* color, int x2, int y2);
	void print() override;
};

