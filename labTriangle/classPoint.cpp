#include "classPoint.h"

Point::Point(double first, double second) {
	x = new double{ first };
	y = new double{ second };
};
Point::~Point() {
	delete x;
	x = nullptr;
	delete y;
	y = nullptr;
}
Point::Point(const Point& other) {
	x = new double{*other.x};
	y = new double{*other.y};
}
void Point::moveX(double moveX) {
	*x += moveX;
}
void Point::moveY(double moveY) {
	*y += moveY;
}
double const Point::distanceToOrigin() {
	return std::sqrt((*x) * (*x) + (*y) * (*y));
}
double const Point::distanceTo(const Point& other) {
	return std::sqrt((*x - *other.x) * (*x - *other.x) + (*y - *other.y) * (*y - *other.y));
}
std::pair<double, double> Point::ToPolar() {
	double r = distanceToOrigin();					//radius
	double angle = std::atan2(*y, *x);
	return{ r, angle };
}
bool Point::operator==(const Point& other) {
	return(*x == *other.x && *y == *other.y);
}
bool Point::operator!=(const Point& other) {
	return !(*this == other);
}
double Point::getX() const {
	return *x;
}
double Point::getY() const {
	return *y;
}
void Point::setX(double setX) {
	*x = setX;
}
void Point::setY(double setY) {
	*y = setY;
}
std::string Point::printCoord() const {
	return std::to_string(*x) + " " + std::to_string(*y);
}
