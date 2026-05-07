#include "Triangle.h"

bool Triangle::isValid(const Point& p1, const Point& p2, const Point& p3) const
{
	double dAB = p1.getDist(p2);
	double dAC = p1.getDist(p3);
	double dBC = p2.getDist(p3);

	if (dAB + dAC <= dBC || dAB + dBC <= dAC || dAC + dBC <= dAB)
		return false;

	return true;
}

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3) : Shape(3)
{
	if (!isValid(p1, p2, p3))
	{
		Shape::free();
		throw "Invalid triangle parameters";
	}

	setPointAtIndex(p1, 0);
	setPointAtIndex(p2, 1);
	setPointAtIndex(p3, 2);
}

double Triangle::getArea() const
{
	const Point& p1 = getPointAtIndex(0);
	const Point& p2 = getPointAtIndex(1);
	const Point& p3 = getPointAtIndex(2);

	double dAB = p1.getDist(p2);
	double dAC = p1.getDist(p3);
	double dBC = p2.getDist(p3);

	double halpPerimeter = (dAB + dBC + dAC) / 2;

	return sqrt(halpPerimeter * (halpPerimeter - dAB) * (halpPerimeter - dAC) * (halpPerimeter - dBC));
}

double Triangle::getPerimeter() const
{
	const Point& p1 = getPointAtIndex(0);
	const Point& p2 = getPointAtIndex(1);
	const Point& p3 = getPointAtIndex(2);
	double dAB = p1.getDist(p2);
	double dAC = p1.getDist(p3);
	double dBC = p2.getDist(p3);

	return dAB + dBC + dAC;
}
