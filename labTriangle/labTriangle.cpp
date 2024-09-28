#include <cmath>
#include <iostream>
#include <string>

#include "classPoint.h"
#include "classTriangle.h"

Point::Point(double first, double second) :x(first), y(second) {};

void Point::moveX(double moveX) {
	x += moveX;
}
void Point::moveY(double moveY) {
	y += moveY;
}
double const Point::distanceToOrigin() {
	return std::sqrt(x * x + y * y);
}
double const Point::distanceTo(const Point& other) {
	return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}
std::pair<double, double> Point::ToPolar() {
	double r = distanceToOrigin();					//radius
	double angle = std::atan2(y, x);
	return{ r, angle };
}
bool Point::operator==(const Point& other) {
	return(x == other.x && y == other.y);
}
bool Point::operator!=(const Point& other) {
	return !(*this == other);
}
double Point::getX() const {
	return x;
}
double Point::getY() const {
	return y;
}
void Point::setX(double x) {
	this->x = x;
}
void Point::setY(double y) {
	this->y = y;
}
std::string Point::printCoord() const {
	return std::to_string(x) + " " + std::to_string(y);
}


Triangle::Triangle(const Point& first, const Point& second, const Point& third) :coordFirst(first), coordSecond(second), coordThird(third) {};

double Triangle::getSide(const Point& point, const Point& point2) {
	double side = std::sqrt(((point2.getX() - point.getX()) * (point2.getX() - point.getX())) + (point2.getY() - point.getY()) * (point2.getY() - point.getY()));
	return side;
}
double Triangle::getAngle(const Point& A, const Point& B, const Point& C) {				//первые переданный означанает что для него ищем угол
	const double PI = 3.141592653589793116;
	double a = getSide(B, C);
	double b = getSide(C, A);
	double c = getSide(A, B);

	double cosA = (b * b + c * c - a * a) / (2 * b * c);
	if (cosA < -1.0 || cosA > 1.0)
		cout << "Error" << endl;
	double angleInRadians = std::acos(cosA);

	double angleInDegrees = angleInRadians * (180.0 / PI);
	return angleInDegrees;
}
double Triangle::triangleArea(const Point& point, const Point& point2, const Point& point3) {		//вычисление площади
	double a = getSide(point, point2);
	double b = getSide(point2, point3);
	double c = getSide(point, point3);

	double p = (a + b + c) / 2;

	return std::sqrt(p * (p - a) * (p - b) * (p - c));
}
double Triangle::trianglePerimeter(const Point& point, const Point& point2, const Point& point3) {
	return getSide(point, point2) + getSide(point, point3) + getSide(point2, point3);
}
double Triangle::triangleHeight(const Point& point, const Point& point2, const Point& point3) {		//первые два передаваемый параметр это относительно этой стороны будет вычисляться высота
	return ((2 * triangleArea(point, point2, point3)) / getSide(point, point2));
}
void Triangle::determineTypeTriangle(const Point& point, const Point& point2, const Point& point3) {
	double angle = getAngle(point, point2, point3) + getAngle(point2, point, point3) + getAngle(point3, point, point2);
	if ((angle <= 180) && (angle >= 179.98)) {
		double a = getSide(point, point2);
		double b = getSide(point, point3);
		double c = getSide(point2, point3);

		double first = getAngle(point, point2, point3);
		double second = getAngle(point2, point, point3);
		double third = getAngle(point3, point, point2);

		if ((a == b) && (b == c)) {
			cout << "Треугольник является равносторонним" << endl;
		}
		if (((a == b) || (a == c) || (b == c))) {
			cout << "Треугольник является равнобедренным" << endl;
		}
		if (((first <= 90.98) && (first >= 89.98)) || (second <= 90.98) && (second >= 89.98) || (third <= 90.98) && (third >= 89.98)) {
			cout << "Треугольник является прямоугольным" << endl;
		}
	}
	else {
		cout << "Углы не образуют треугольник" << endl;
		return;
	}
}
Point Triangle::getCoordFirst() const {
	return coordFirst;
}
Point Triangle::getCoordSecond() const {
	return coordSecond;
}
Point Triangle::getCoordThird() const {
	return coordThird;
}
void Triangle::dispay() const {
	cout << coordFirst.getX() << endl;
}

void eighthСase() {
	system("cls");
	Point first, second, third;
	unsigned int choiceForDo = 0;
	cout << "Для выполнения этого блока потребуется создать три координаты для представления треугольника. Ввод в формате (X Y): " << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "Ввод : ";
		if (i == 0) {
			double x, y;
			cin >> x >> y;
			first.setX(x);
			first.setY(y);
		}
		else if (i == 1) {
			double x, y;
			cin >> x >> y;
			second.setX(x);
			second.setY(y);
		}
		else {
			double x, y;
			cin >> x >> y;
			third.setX(x);
			third.setY(y);
		}
		cout << endl;
	}
	Triangle triangle(first, second, third);
	do {
		system("cls");
		cout << "1. Вычислить площадь\n" <<
			"2. Вычислить периметр\n" <<
			"3. Вычислить высоту\n" <<
			"4. Определить вид треугольника\n" <<
			"5. Вернуться меню\n" << endl;
		unsigned int choice = 0;
		while (true) {
			cout << "Ввод : ";
			cin >> choice;
			choiceForDo = choice;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else if (choice < 6) {
				break;
			}
		}

		switch (choice)
		{
		case(1): {
			cout << triangle.triangleArea(triangle.getCoordFirst(), triangle.getCoordSecond(), triangle.getCoordThird()) << endl;
			system("pause");
			break;
		}
		case(2): {
			cout << triangle.trianglePerimeter(triangle.getCoordFirst(), triangle.getCoordSecond(), triangle.getCoordThird()) << endl;
			system("pause");
			break;
		}
		case(3): {
			system("cls");
			cout << "Выберите на какую сторону будет опущена высота (Запись в виде коорд-коорд):\n\n" <<
				"1. 1-2\n" <<
				"2. 2-3\n" <<
				"3. 1-3\n" << endl;
			unsigned int choice = 0;
			cout << "Ввод : ";
			cin >> choice;
			if (choice == 1) {
				cout << "Высота = " << triangle.triangleHeight(triangle.getCoordFirst(), triangle.getCoordSecond(), triangle.getCoordThird()) << endl;
			}
			else if (choice == 2) {
				cout << "Высота = " << triangle.triangleHeight(triangle.getCoordSecond(), triangle.getCoordThird(), triangle.getCoordFirst()) << endl;
			}
			else if (choice == 3) {
				cout << "Высота = " << triangle.triangleHeight(triangle.getCoordFirst(), triangle.getCoordThird(), triangle.getCoordSecond()) << endl;
			}
			else {
				break;
			}
			system("pause");
			break;
		}
		case(4): {
			triangle.determineTypeTriangle(triangle.getCoordFirst(), triangle.getCoordSecond(), triangle.getCoordThird());
			system("pause");
			break;
		}
		default:
			break;
		}




	} while (choiceForDo != 5);

}

void program() {
	setlocale(LC_ALL, "ru");
	unsigned int choiceForDo = 0;
	Point point;
	do {
		system("cls");
		cout << "Меню: \n\n" <<
			"1. Создать точку\n" <<
			"2. Перемещение точки по оси X\n" <<
			"3. Перемещение точки по оси Y\n" <<
			"4. Определить расстояние от точки до начала координат\n" <<
			"5. Определить расстояние между двумя точками\n" <<
			"6. Преобразовать в полярные координаты\n" <<
			"7. Сравнить на совпадение / несовпадение\n" <<
			"8. Перейти к методам номера 25\n" <<
			"9. Выход\n" << endl;
		unsigned int choice = 0;
		while (true) {
			cout << "Ввод : ";
			cin >> choice;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else if (choice < 10) {
				break;
			}
		}
		choiceForDo = choice;
		switch (choice)
		{
		case(1): {
			double x, y;
			cout << "Введите координату в формате (X Y) : ";
			cin >> x >> y;
			point.setX(x);
			point.setY(y);
			break;
		}
		case(2): {
			double x;
			cout << "Введите на сколько осуществить сдвиг: ";
			cin >> x;
			point.moveX(x);
			cout << "Актуальные данные: " << point.printCoord() << endl;
			system("pause");
			break;
		}
		case(3): {
			double y;
			cout << "Введите на сколько осуществить сдвиг: ";
			cin >> y;
			point.moveY(y);
			cout << "Актуальные данные: " << point.printCoord() << endl;
			system("pause");
			break;
		}
		case(4): {
			cout << "Расстояние от точки до начала координат = " << point.distanceToOrigin() << endl;
			system("pause");
			break;
		}
		case(5): {
			Point point2;
			double x, y;
			cout << "Введите координату в формате (X Y) : ";
			cin >> x >> y;
			point2.setX(x);
			point2.setY(y);
			cout << "Расстояние от исходной точки до новой = " << point.distanceTo(point2) << endl;
			system("pause");
			break;
		}
		case(6): {
			auto polar = point.ToPolar();
			double r = polar.first;
			double theta = polar.second;
			cout << "radius: " << r << ", theta: " << theta << endl;
			system("pause");
			break;
		}
		case(7): {
			Point point2;
			double x, y;
			cout << "Введите координату в формате (X Y) : ";
			cin >> x >> y;
			point2.setX(x);
			point2.setY(y);
			cout << "Совпадение : " << (point == point2) << endl;
			cout << "НЕ совпадение : " << (point != point2) << endl;
			system("pause");
			break;
		}
		case(8): {
			eighthСase();
			break;
		}
		case(9): {
			break;
		}

		default:
			break;
		}
	} while (choiceForDo != 9);
}