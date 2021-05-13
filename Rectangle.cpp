#include "Rectangle.h"

Rectangle::Rectangle():Shape()
{
	this->width = 0;
	this->height = 0;
	strcpy_s(fill, 5, "none");
}

Rectangle::Rectangle(int width, int height, const char* fill) :Shape(x, y, stroke, strokeWidth) {
	this->width = width;
	this->height = height;
	strcpy_s(this->fill, strlen(fill) + 1, fill);

}

void Rectangle::print()
{
	std::cout << "rectangle " << this->x << " " << this->y << " " << this->width << " " << this->height << " " << this->fill << " " << stroke << " " << strokeWidth << std::endl;
}
