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
	inline void  moveX(double moveX);
	inline void moveY(double moveY);
	double const distanceToOrigin();
	double const distanceTo(const Point& other);
	std::pair<double, double> ToPolar();
	bool operator==(const Point& other);	
	bool operator!=(const Point& other);
	inline double getX() const;
	inline double getY() const;
	inline void setX(double x);
	inline void setY(double y);
	std::string printCoord() const;
	~Point();
};
