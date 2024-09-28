#pragma once

#define cout std::cout
#define endl std::endl
#define cin std::cin

#include "classPoint.h"

class Triangle {
	Point coordFirst, coordSecond, coordThird;
public:
	Triangle(const Point& first, const Point& second, const Point& third);
	double getSide(const Point& point, const Point& point2);
	double getAngle(const Point& A, const Point& B, const Point& C);				//первые переданный означанает что для него ищем угол
	double triangleArea(const Point& point, const Point& point2, const Point& point3);		//вычисление площади
	double trianglePerimeter(const Point& point, const Point& point2, const Point& point3);
	double triangleHeight(const Point& point, const Point& point2, const Point& point3);		//первые два передаваемый параметр это относительно этой стороны будет вычисляться высота
	void determineTypeTriangle(const Point& point, const Point& point2, const Point& point3);
	Point getCoordFirst() const;
	Point getCoordSecond() const;
	Point getCoordThird() const;
	void dispay() const;
};