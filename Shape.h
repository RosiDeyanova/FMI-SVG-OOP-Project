#pragma once
#include<cstring>
class Shape
{
public:
	Shape();
	Shape(int x, int y, const char* stroke, int strokeWidth);

protected:
	int x;
	int y;
	char stroke[10];
	int strokeWidth;

};






