#include "Circle.h"

Circle::Circle() :Shape()
{
	this->r = 0;
	strcpy_s(fill, 5, "none");
}
Circle::Circle(int r, const char* fill) : Shape(x, y, stroke,strokeWidth) {
	this->r = r;
	strcpy_s(this->fill, strlen(fill) + 1, fill);

}
void Circle::print()
{
	std::cout << "circle " << this->x << " " << this->y << " " << this->r << " " << this->fill << " " << stroke << " " << strokeWidth << std::endl;
}