#pragma once
#include <cmath>

struct Point
{
	double x, y;

	Point() : x(0), y(0) {};
	Point(double x, double y) : x(x), y(y) {};

	double getDist(const Point& other) const
	{
		double dx = x - other.x;
		double dy = y - other.y;

		return sqrt(dx * dx + dy * dy);
	}

};

class Shape
{
private:

	Point* points = nullptr;
	int count;

	void copyFrom(const Shape& other);

protected:

	const Point& getPointAtIndex(int index) const;
	void setPointAtIndex(const Point& p, int index);
	void free();

public:

	Shape(int count);
	Shape(const Shape& other);
	Shape& operator=(const Shape& other);
	virtual ~Shape();

	virtual double getPerimeter() const = 0;
	virtual double getArea() const = 0;

};

