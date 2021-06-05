#pragma once
#include<cstring>
class Shape
{
public:
	Shape();
	~Shape();
	Shape(char* name, int x, int y, char* color);

	char* getName() { return this->name; }
	virtual void print() = 0;
	void setX(int x);
	void setY(int y);
	void setColor(char* color);



protected:
	char* name;
	int x;
	int y;
	char* color;

};






