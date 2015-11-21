#pragma once 
#include "stdafx.h"
#include <iostream>

class rectangle
{
	double width, height;
public:
	double S();
	double P();
	rectangle();
	rectangle(double width, double height);
	rectangle(const rectangle &);
	~rectangle();
	int Type();
	static enum {
		square,
		rect
	};

	void print();
	friend std::ostream& operator <<(std::ostream& out, rectangle& x)
	{
		out << x.width << ":" << x.height;
		return out;
	}
	void Setwidth(double wi);
	void Setheight(double hei);
	double Getwidth();
	double Getheight();

};