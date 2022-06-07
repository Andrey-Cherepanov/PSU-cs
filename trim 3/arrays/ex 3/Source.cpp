#include <iostream>
using namespace std;

//Constants
const int n = 10;
int arr1[n];
int arr2[n];
int arr3[n] = { 0 };

void display();
void init_arrays();
void sum_of_arrays(int len, int* A, int* B, int* res);


int main() {
	setlocale(0, "");
	init_arrays();
	display();
	sum_of_arrays(n, arr1, arr2, arr3);
	cout << "\nМассив, полученный как сумма исходных:\n";
	for (int i = 0; i < n; i++) cout << arr3[i] << " ";
	cout << "\n";
}


//Вывод массивов
void display() {
	for (int i = 0; i < n; i++) cout << arr1[i] << " ";
	cout << "\n";
	for (int i = 0; i < n; i++) cout << arr2[i] << " ";
	cout << "\n";
}

//Заполнение массивов
void init_arrays() {
	for (int i = 0; i < n; i++) {
		arr1[i] = rand() % 10;
		arr2[i] = rand() % 10;
	}
}

//Сумма массивов
void sum_of_arrays(int len, int* A, int* B, int* res)
{
	for (int i = 0; i < n; i++) res[i] = A[i] + B[i];
}