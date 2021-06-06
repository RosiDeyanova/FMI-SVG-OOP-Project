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
	void writeOut(std::ostream& out) override;
	void setX2(int x2);
	void setY2(int y2);
	int getX2();
	int getY2();
};

