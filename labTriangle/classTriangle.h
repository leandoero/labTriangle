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
	double getAngle(const Point& A, const Point& B, const Point& C);				//������ ���������� ���������� ��� ��� ���� ���� ����
	double triangleArea(const Point& point, const Point& point2, const Point& point3);		//���������� �������
	double trianglePerimeter(const Point& point, const Point& point2, const Point& point3);
	double triangleHeight(const Point& point, const Point& point2, const Point& point3);		//������ ��� ������������ �������� ��� ������������ ���� ������� ����� ����������� ������
	void determineTypeTriangle(const Point& point, const Point& point2, const Point& point3);
	Point getCoordFirst() const;
	Point getCoordSecond() const;
	Point getCoordThird() const;
	void dispay() const;
};