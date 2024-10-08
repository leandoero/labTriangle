#include "classTriangle.h"

Triangle::Triangle(const Point& first, const Point& second, const Point& third) :coordFirst(first), coordSecond(second), coordThird(third) {};

double Triangle::getSideFirstSecond() {
	double side = std::sqrt(((coordSecond.getX() - coordFirst.getX()) * (coordSecond.getX() - coordFirst.getX())) + (coordSecond.getY() - coordFirst.getY()) * (coordSecond.getY() - coordFirst.getY()));
	return side;
}
double Triangle::getSideFirstThird() {
	double side = std::sqrt(((coordThird.getX() - coordFirst.getX()) * (coordThird.getX() - coordFirst.getX())) + (coordThird.getY() - coordFirst.getY()) * (coordThird.getY() - coordFirst.getY()));
	return side;
}
double Triangle::getSideSecondThird() {
	double side = std::sqrt(((coordThird.getX() - coordSecond.getX()) * (coordThird.getX() - coordSecond.getX())) + (coordThird.getY() - coordSecond.getY()) * (coordThird.getY() - coordSecond.getY()));
	return side;
}

double Triangle::getAngleAcrossFirstSecond() {	
	const double PI = 3.141592653589793116;
	double a = getSideFirstSecond();
	double b = getSideFirstThird();
	double c = getSideSecondThird();

	double cosA = (b * b + c * c - a * a) / (2 * b * c);
	double angleInRadians = std::acos(cosA);

	double angleInDegrees = angleInRadians * (180.0 / PI);
	return angleInDegrees;
}

double Triangle::getAngleAcrossFirstThird() {
	const double PI = 3.141592653589793116;
	double a = getSideFirstThird();
	double b = getSideFirstSecond();
	double c = getSideSecondThird();

	double cosA = (b * b + c * c - a * a) / (2 * b * c);
	if (cosA < -1.0 || cosA > 1.0)
		cout << "Error" << endl;
	double angleInRadians = std::acos(cosA);

	double angleInDegrees = angleInRadians * (180.0 / PI);
	return angleInDegrees;
}

double Triangle::getAngleAcrossSecondThird() {
	const double PI = 3.141592653589793116;
	double a = getSideSecondThird();
	double b = getSideFirstSecond();
	double c = getSideFirstThird();

	double cosA = (b * b + c * c - a * a) / (2 * b * c);
	if (cosA < -1.0 || cosA > 1.0)
		cout << "Error" << endl;
	double angleInRadians = std::acos(cosA);

	double angleInDegrees = angleInRadians * (180.0 / PI);
	return angleInDegrees;
}


double Triangle::triangleArea() {		//вычисление площади
	double a = getSideFirstSecond();
	double b = getSideSecondThird();
	double c = getSideFirstThird();

	double p = (a + b + c) / 2;

	return std::sqrt(p * (p - a) * (p - b) * (p - c));
}
double Triangle::trianglePerimeter() {
	return getSideFirstSecond() + getSideFirstThird() + getSideSecondThird();
}
double Triangle::triangleHeight(unsigned int index) {		//первые два передаваемый параметр это относительно этой стороны будет вычисляться высота
	switch (index)
	{
	case 1: {
		return ((2 * triangleArea()) / getSideFirstSecond());
		break;
	}
	case 2: {
		return ((2 * triangleArea()) / getSideSecondThird());
		break;
	}
	case 3: {
		return ((2 * triangleArea()) / getSideFirstThird());
		break;
	}
	default:
		break;
	}
}
void Triangle::determineTypeTriangle() {
	double angle = getAngleAcrossFirstSecond() + getAngleAcrossFirstThird() + getAngleAcrossSecondThird();
	if ((angle <= 180.02) && (angle >= 179.98)) {
		double a = getSideFirstSecond();
		double b = getSideFirstThird();
		double c = getSideSecondThird();

		double first = getAngleAcrossFirstSecond();
		double second = getAngleAcrossFirstThird();
		double third = getAngleAcrossSecondThird();

		if ((a == b) && (b == c)) {
			cout << "Треугольник является равносторонним" << endl;
		}
		if (((a == b) || (a == c) || (b == c))) {
			cout << "Треугольник является равнобедренным" << endl;
		}
		if (((first <= 90.02) && (first >= 89.98)) || (second <= 90.02) && (second >= 89.98) || (third <= 90.02) && (third >= 89.98)) {
			cout << "Треугольник является прямоугольным" << endl;
		}
	}
	else {
		cout << "Углы не образуют треугольник" << endl;
		return;
	}
}

