#include "otherFunc.h"

void eighth�ase() {
	system("cls");
	Point first, second, third;
	unsigned int choiceForDo = 0;
	cout << "��� ���������� ����� ����� ����������� ������� ��� ���������� ��� ������������� ������������. ���� � ������� (X Y): " << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "���� : ";
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
		cout << "1. ��������� �������\n" <<
			"2. ��������� ��������\n" <<
			"3. ��������� ������\n" <<
			"4. ���������� ��� ������������\n" <<
			"5. ��������� ����\n" << endl;
		unsigned int choice = 0;
		while (true) {
			cout << "���� : ";
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
			cout << "�������� �� ����� ������� ����� ������� ������ (������ � ���� �����-�����):\n\n" <<
				"1. 1-2\n" <<
				"2. 2-3\n" <<
				"3. 1-3\n" << endl;
			unsigned int index = 0;
			cout << "���� : ";
			cin >> index;
			cout << "������ = " << triangle.triangleHeight(index) << endl;
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
		cout << "����: \n\n" <<
			"1. ������� �����\n" <<
			"2. ����������� ����� �� ��� X\n" <<
			"3. ����������� ����� �� ��� Y\n" <<
			"4. ���������� ���������� �� ����� �� ������ ���������\n" <<
			"5. ���������� ���������� ����� ����� �������\n" <<
			"6. ������������� � �������� ����������\n" <<
			"7. �������� �� ���������� / ������������\n" <<
			"8. ������� � ������� ������ 25\n" <<
			"9. �����\n" << endl;
		unsigned int choice = 0;
		while (true) {
			cout << "���� : ";
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
			cout << "������� ���������� � ������� (X Y) : ";
			cin >> x >> y;
			point.setX(x);
			point.setY(y);
			break;
		}
		case(2): {
			double x;
			cout << "������� �� ������� ����������� �����: ";
			cin >> x;
			point.moveX(x);
			cout << "���������� ������: " << point.printCoord() << endl;
			system("pause");
			break;
		}
		case(3): {
			double y;
			cout << "������� �� ������� ����������� �����: ";
			cin >> y;
			point.moveY(y);
			cout << "���������� ������: " << point.printCoord() << endl;
			system("pause");
			break;
		}
		case(4): {
			cout << "���������� �� ����� �� ������ ��������� = " << point.distanceToOrigin() << endl;
			system("pause");
			break;
		}
		case(5): {
			Point point2;
			double x, y;
			cout << "������� ���������� � ������� (X Y) : ";
			cin >> x >> y;
			point2.setX(x);
			point2.setY(y);
			cout << "���������� �� �������� ����� �� ����� = " << point.distanceTo(point2) << endl;
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
			cout << "������� ���������� � ������� (X Y) : ";
			cin >> x >> y;
			point2.setX(x);
			point2.setY(y);
			cout << "���������� : " << (point == point2) << endl;
			cout << "�� ���������� : " << (point != point2) << endl;
			system("pause");
			break;
		}
		case(8): {
			eighth�ase();
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