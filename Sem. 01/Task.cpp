#include <iostream>

struct Point
{
	double x;
	double y;
};

void readPoint(Point& p)
{
	std::cin >> p.x >> p.y;
}

void printPoint(const Point& p)
{
	std::cout << p.x << " " << p.y << std::endl;
}

struct Triangle
{
	Point p1;
	Point p2;
	Point p3;
};

void readTriangle(Triangle& t)
{
	readPoint(t.p1);
	readPoint(t.p2);
	readPoint(t.p3);
}

void printTriangle(const Triangle& t)
{
	std::cout << "p 1: ";
	printPoint(t.p1);
	std::cout << "p 2: ";
	printPoint(t.p2);
	std::cout << "p 3: ";
	printPoint(t.p3);
}

double dist(const Point& p1, const Point& p2)
{
	double dx = p1.x - p2.x;
	double dy = p1.y - p2.y;

	return std::sqrt(dx * dx + dy * dy);
}

double triangleArea(const Triangle& t)
{
	double sideA = dist(t.p1, t.p2);
	double sideB = dist(t.p1, t.p3);
	double sideC = dist(t.p2, t.p3);

	double halfPer = (sideA + sideB + sideC) / 2;

	return std::sqrt(halfPer * (halfPer - sideA) * (halfPer - sideB) * (halfPer - sideC));
}

double* getAreas(const Triangle* triangles, size_t size)
{
	double* triangleAreas = new double[size];

	for (size_t i = 0; i < size; i++)
	{
		triangleAreas[i] = triangleArea(triangles[i]);
	}

	return triangleAreas;
}

void selectionSort(double* areas, size_t size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		size_t minIndex = i;

		for (size_t j = i + 1; j < size; j++)
		{
			if (areas[j] < areas[minIndex])
			{
				minIndex = j;
			}
		}
			
		if (minIndex != i)
		{
			std::swap(areas[minIndex], areas[i]);
		}
	}
}

int main()
{
	size_t n;
	std::cin >> n;

	Triangle* triangleArr = new Triangle[n];

	for (size_t i = 0; i < n; i++)
	{
		readTriangle(triangleArr[i]);
	}

	double* areas = getAreas(triangleArr, n);

	selectionSort(areas, n);

	for (size_t i = 0; i < n; i++)
	{
		std::cout<< areas[i] << " ";
	}

	delete[] triangleArr;
	delete[] areas;
}
