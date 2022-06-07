#include <iostream>
using namespace std;

double ex1(int p, int x) {
	double B = 0;
	for (int n = 1; n <= p; B += (pow(x, n) / pow(2 * n + 1, 2 * p)), n++);
	return B;
};

int ex2(int R) {
	int Z = 0;
	int s;
	for (int k = 1; k <= 20; k++) {
		s = 0;
		for (int n = 1; n <= 15; n++) {
			s += pow(R - n, 2);
		}
		Z += pow(R, 3) * s;
	}
	return Z;
}

void ex3(double a, double b, double h) {
	double y, z1, z2;
	cout << "x\t\ty\t\tz1\t\tz2\n";
	for (double x = a; x <= b; x += h) {
		y = asin(x + x * x);
		z1 = y * y;
		z2 = abs(y);

		cout << round(x * 1000) / 1000 << "\t\t" << round(y * 1000) / 1000
			<< "\t\t" << round(z1 * 1000) / 1000 << "\t\t" << round(z2 * 1000) / 1000 << "\n";
	}
}

bool ex4(double x, double y) {
	if ((abs(x) < 0.5 && abs(y) < 0.5) || (abs(x) > 1) || (abs(y) > 1)) return false;
	return true;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int x, p;
	//Задание 1
	cout << "Задание 1:\nВведите x: "; cin >> x; cout << "Введите p: "; cin >> p;
	cout << "B = " << ex1(x, p) << "\n";

	//Задание 2
	int R;
	cout << "\nЗадание 2:\nВведите R: "; cin >> R;
	cout << "R = " << ex2(R) << "\n";

	//Задание 3
	double a, b, h;
	cout << "\nЗадание 3\nВведите левую границу отрезка: "; cin >> a;
	cout << "Введите правую границу отрезка: "; cin >> b;
	cout << "Введите шаг: "; cin >> h;
	ex3(a, b, h);

	//Задание 4
	double x1, y;
	cout << "\nЗадание 4\nВведите координату x: "; cin >> x1;
	cout << "Введите координату y: "; cin >> y;
	string res = ex4(x1, y) ? "принадлежит " : "не принадлежит ";
	cout << "Точка " << "(" << x1 << ", " << y << ") " << res << "области";
}
