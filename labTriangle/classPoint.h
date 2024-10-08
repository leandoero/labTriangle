#pragma once
#include <iostream>
#include <string>

#define cout std::cout
#define endl std::endl
#define cin std::cin

class Point {
	double* x;
	double* y;
public:
	Point(double first = 0.0, double second = 0.0);
	Point(const Point& other);
	void  moveX(double moveX);
	void moveY(double moveY);
	double const distanceToOrigin();
	double const distanceTo(const Point& other);
	std::pair<double, double> ToPolar();
	bool operator==(const Point& other);	
	bool operator!=(const Point& other);
	double getX() const;
	double getY() const;
	void setX(double x);
	void setY(double y);
	std::string printCoord() const;
	~Point();
};
