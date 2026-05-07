#pragma once
#include "Shape.h"

class Triangle : public Shape
{

private:

	bool isValid(const Point& p1, const Point& p2, const Point& p3) const;

public:

	Triangle(const Point& p1, const Point& p2, const Point& p3);


	virtual double getArea() const override;
	virtual double getPerimeter() const override;
};

