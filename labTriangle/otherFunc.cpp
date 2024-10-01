#include "otherFunc.h"

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
			cout << triangle.triangleArea() << endl;
			system("pause");
			break;
		}
		case(2): {
			cout << triangle.trianglePerimeter() << endl;
			system("pause");
			break;
		}
		case(3): {
			system("cls");
			cout << "Выберите на какую сторону будет опущена высота (Запись в виде коорд-коорд):\n\n" <<
				"1. 1-2\n" <<
				"2. 2-3\n" <<
				"3. 1-3\n" << endl;
			unsigned int index = 0;
			cout << "Ввод : ";
			cin >> index;
			cout << "Высота = " << triangle.triangleHeight(index) << endl;
			system("pause");
			break;
		}
		case(4): {
			triangle.determineTypeTriangle();
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