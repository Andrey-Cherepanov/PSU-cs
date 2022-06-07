#include <iostream>
using namespace std;


//Задание 1 (а)
int factA(int n) {
	int res = 1;
	if (n == 0) return 1;
	for (int i = 1; i <= n; i++) res *= i;
	return res;
}


//Задание 1 (б)
int factB(int n) {
	if (n == 0) return 1;
	return factB(n - 1) * n;
}

//Задание 2
void squares(int n) {
	if (n == 0) cout << "рекурсивный вызов для a = 0: a^2 = 0\n";
	else {
		squares(n - 1);
		cout << "рекурсивный вызов для a = " << n << ": a^2 = " << n * n << "\n";
	}
}


//Задание 3
int digit_sum(int num) {
	num = abs(num);
	if (num < 10) return num;
	else return digit_sum(num / 10) + num % 10;
}


// Задание 4
int NOD(int a, int b) {
	if (a == b) return a;
	else if (a > b) return NOD(a - b, b);
	else return NOD(a, b - a);
}



int main() {
	setlocale(0, "");
	int n;
	cout << "Введите число, для вычисления факториала: "; cin >> n;
	cout << "Реккурентный способ: " << factA(n) << "\n";
	cout << "Рекурсивный способ: " << factB(n) << "\n\n";
	cout << "Введите число, для вычисления квадратов: "; cin >> n;
	squares(n);
	cout << "\nСумма цифр в числе:\n";
	for (int i = 0; i < 5; i++) {
		int num;
		cout << "\nВведите число: ";
		cin >> num;
		cout << "Сумма цифр = " << digit_sum(num);

	}
	cout << "\nНОД двух чисел:\n";
	int a, b;
	cout << "Введите первое число: ";
	cin >> a;
	cout << "Введите второе число: ";
	cin >> b;
	cout << "НОД(a, b) = " << NOD(a, b);
}