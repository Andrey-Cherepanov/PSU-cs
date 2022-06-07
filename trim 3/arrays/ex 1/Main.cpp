#include <iostream>
using namespace std;

//Constants
const int n = 10;

int arr[n];

//Methods
void display();
void init_array();
double array_avg(int n, int* A);
void double_odd(int n, int* A);


int main() {
	setlocale(0, "");
	init_array();
	display();
	double avg = array_avg(n, arr);
	printf("Среднее арифметическое элеметов массива = %4.2f\n", avg);

	cout << "\nМассив с удвоенными нечетными элементами:\n";
	double_odd(n, arr);
	display();

}

void display() {
	//Вывод массива 
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
	cout << "\n";
}

void init_array() {
	//Заполнение массива
	for (int i = 0; i < n; i++) arr[i] = rand() % 10;
}

double array_avg(int n, int* A) {
	//Нахождение среднего
	double avg = 0;
	for (int i = 0; i < n; i++) avg += A[i];
	avg /= n;
	return avg;
}

void double_odd(int n, int* A) {
	//Умножение нечетных элементов на 2
	for (int i = 0; i < n; i++) {
		if (A[i]%2 == 1) A[i] *= 2;
	}
}