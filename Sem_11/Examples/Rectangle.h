#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
	double width;
	double height;

public:

	Rectangle(const Point& p, double width, double height);

	const Point& getBottomLeftPoint() const;

	double getWidth() const;
	double getHeight() const;

	virtual double getArea() const override;
	virtual double getPerimeter() const override;

};

