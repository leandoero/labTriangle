#pragma once
#include <iostream>
#include "classPoint.h"

#define cout std::cout
#define endl std::endl
#define cin std::cin

class Triangle {
	Point coordFirst, coordSecond, coordThird;
public:
	/*можно еще допилить оператор присваивания потому что 
	Triangle::Triangle(const Point& first, const Point& second, const Point& third) :coordFirst(first), coordSecond(second), coordThird(third) {};
	в этой строчке срабатывает конструктор копирования в Point, но если бы я прописывал непосредственно тело то возникла бы проблема.
	Поэтому стоило бы перегрузить присваивание.
	*/
	Triangle(const Point& first, const Point& second, const Point& third);
	double getSideFirstSecond();
	double getSideSecondThird();
	double getSideFirstThird();
	double getAngleAcrossFirstSecond();
	double getAngleAcrossFirstThird();
	double getAngleAcrossSecondThird();
	double triangleArea();		//вычисление площади
	double trianglePerimeter();
	double triangleHeight(unsigned int index);		
	void determineTypeTriangle();
};