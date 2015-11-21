#include "StdAfx.h"
#include "rectangle.h"
#include <iostream>
using namespace std;
rectangle::rectangle()
{
	width = rand() % 10 + 1;
	height = rand() % 10 + 1;
}
rectangle::rectangle(double width_, double height_)

{
	width = width_;
	height = height_;
}
rectangle::~rectangle()
{

}
double rectangle::S()
{
	return width*height;
}
double rectangle::P()
{
	return 2 * (width + height);
}
int rectangle::Type()
{
	return (width == height) ? 0 : 1;
}

void rectangle::print()
{
	std::cout << width << ":" << height << std::endl;
}

void rectangle::Setheight(double hei)
{
	if (height>0) height = hei;
}
void rectangle::Setwidth(double wi)
{
	if (width>0) width = wi;
}
double rectangle::Getheight()
{
	return height;
}
double rectangle::Getwidth()
{
	return width;
}
rectangle::rectangle(const rectangle &m)
{
	width = m.width;
	height = m.height;
}