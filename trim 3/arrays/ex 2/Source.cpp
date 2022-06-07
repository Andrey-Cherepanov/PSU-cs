#include <iostream>
using namespace std;

//Constants
const int n = 9;
int arr[n];

void display();
void init_array();
void reverse_array(int len, int* A);
void swap_pairs(int len, int* A);

int main() {
	init_array();
	display();

	reverse_array(n, arr);
	display();

	cout << "\n";

	init_array();
	display();
	swap_pairs(n, arr);
	display();
}

//Вывод  массива
void display() {
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
	cout << "\n";
}

//Заполнение массива
void init_array() {
	for (int i = 0; i < n; i++) arr[i] = rand() % 10;
}

//Перевернуть массив
void reverse_array(int len, int* A)
{
	for (int i = 0; i < (len) / 2; i++) swap(A[i], A[len-i-1]);	
}


//Поменять пары
void swap_pairs(int len, int* A)
{
	if (len % 2 == 0) {
		for (int i = 0; i < len - 1; i += 2) swap(A[i], A[i + 1]);
	}
	else {
		for (int i = 0; i < len - 2; i += 2) swap(A[i], A[i + 1]);
	}
}