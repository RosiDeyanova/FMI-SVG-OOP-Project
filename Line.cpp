#include "Line.h"

Line::Line() :Shape()
{
	this->x2 = 0;
	this->y2 = 0;
}
Line::Line(int x2, int y2) : Shape(x, y, stroke, strokeWidth) {
	this->x2 = x2;
	this->y2 = y2;

}
void Line::print()
{
	std::cout << "line " << this->x << " " << this->y << " " << this->x2 << " " << this->y2 << " " << stroke << " " << strokeWidth << std::endl;
}
