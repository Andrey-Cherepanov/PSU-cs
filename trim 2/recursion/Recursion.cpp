#include <iostream>
using namespace std;


//������� 1 (�)
int factA(int n) {
	int res = 1;
	if (n == 0) return 1;
	for (int i = 1; i <= n; i++) res *= i;
	return res;
}


//������� 1 (�)
int factB(int n) {
	if (n == 0) return 1;
	return factB(n - 1) * n;
}

//������� 2
void squares(int n) {
	if (n == 0) cout << "����������� ����� ��� a = 0: a^2 = 0\n";
	else {
		squares(n - 1);
		cout << "����������� ����� ��� a = " << n << ": a^2 = " << n * n << "\n";
	}
}


//������� 3
int digit_sum(int num) {
	num = abs(num);
	if (num < 10) return num;
	else return digit_sum(num / 10) + num % 10;
}


// ������� 4
int NOD(int a, int b) {
	if (a == b) return a;
	else if (a > b) return NOD(a - b, b);
	else return NOD(a, b - a);
}



int main() {
	setlocale(0, "");
	int n;
	cout << "������� �����, ��� ���������� ����������: "; cin >> n;
	cout << "������������ ������: " << factA(n) << "\n";
	cout << "����������� ������: " << factB(n) << "\n\n";
	cout << "������� �����, ��� ���������� ���������: "; cin >> n;
	squares(n);
	cout << "\n����� ���� � �����:\n";
	for (int i = 0; i < 5; i++) {
		int num;
		cout << "\n������� �����: ";
		cin >> num;
		cout << "����� ���� = " << digit_sum(num);

	}
	cout << "\n��� ���� �����:\n";
	int a, b;
	cout << "������� ������ �����: ";
	cin >> a;
	cout << "������� ������ �����: ";
	cin >> b;
	cout << "���(a, b) = " << NOD(a, b);
}