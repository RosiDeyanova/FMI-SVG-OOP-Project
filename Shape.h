#pragma once
#include<cstring>
#include<fstream>
class Shape
{
public:
	Shape();
	~Shape();
	Shape(char* name, int x, int y, char* color);

	char* getName() { return this->name; }
	virtual void print() = 0;
	virtual void writeOut(std::ostream& out) = 0;
	void setX(int x);
	void setY(int y);
	void setColor(char* color);
	int getX();
	int getY();
	char* getColor();


protected:
	char* name;
	int x;
	int y;
	char* color;

};






