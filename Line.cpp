#include "Line.h"

Line::Line() :Shape()
{
	this->x2 = 0;
	this->y2 = 0;
}
Line::Line(char* name, int x, int y, char* color, int x2, int y2) : Shape(name,x, y,color) {
	this->x2 = x2;
	this->y2 = y2;

}
void Line::print()
{
	std::cout << "line " << this->x << " " << this->y << " " << this->x2 << " " << this->y2 << " " << std::endl;
}
