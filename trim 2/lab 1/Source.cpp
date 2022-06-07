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
	//������� 1
	cout << "������� 1:\n������� x: "; cin >> x; cout << "������� p: "; cin >> p;
	cout << "B = " << ex1(x, p) << "\n";

	//������� 2
	int R;
	cout << "\n������� 2:\n������� R: "; cin >> R;
	cout << "R = " << ex2(R) << "\n";

	//������� 3
	double a, b, h;
	cout << "\n������� 3\n������� ����� ������� �������: "; cin >> a;
	cout << "������� ������ ������� �������: "; cin >> b;
	cout << "������� ���: "; cin >> h;
	ex3(a, b, h);

	//������� 4
	double x1, y;
	cout << "\n������� 4\n������� ���������� x: "; cin >> x1;
	cout << "������� ���������� y: "; cin >> y;
	string res = ex4(x1, y) ? "����������� " : "�� ����������� ";
	cout << "����� " << "(" << x1 << ", " << y << ") " << res << "�������";
}
