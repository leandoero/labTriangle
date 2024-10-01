#pragma once
#include <iostream>
#include "classPoint.h"

#define cout std::cout
#define endl std::endl
#define cin std::cin

class Triangle {
	Point coordFirst, coordSecond, coordThird;
public:
	Triangle(const Point& first, const Point& second, const Point& third);
	double getSideFirstSecond();
	double getSideSecondThird();
	double getSideFirstThird();
	double getAngleAcrossFirstSecond();
	double getAngleAcrossFirstThird();
	double getAngleAcrossSecondThird();
	double triangleArea();		//���������� �������
	double trianglePerimeter();
	double triangleHeight(unsigned int index);		//������ ��� ������������ �������� ��� ������������ ���� ������� ����� ����������� ������
	void determineTypeTriangle();
};