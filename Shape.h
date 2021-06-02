#pragma once
#include<cstring>
class Shape
{
public:
	Shape();
	~Shape();
	Shape(const char* name, int x, int y, const char* color);

	const char* getName() { return this->name; }
	virtual void print() = 0;
	virtual void setName()=0;
	virtual void setX(int x)=0;
	virtual void setY(int y)=0;
	virtual void setColor(char* color)=0;



protected:
	const char* name;
	int x;
	int y;
	char* color;

};






