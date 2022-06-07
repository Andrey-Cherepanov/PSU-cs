#include <iostream>
using namespace std;

//Constants
const int n = 10;
int arr[n];

void display();
void init_array();
void sort_negatives(int len, int* A);


int main() {
	init_array();
	display();
	sort_negatives(n, arr);


	display();
}


//Вывод мвссива
void display() {
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
	cout << "\n";
}

//Заполнение массива
void init_array() {
	for (int i = 0; i < n; i++) arr[i] = rand() % 10 * pow(-1, rand() % 2);
}


//Перемещение отрицательных чисел
void sort_negatives(int len, int* A)
{	
	int temp;
	int i, j;
	for (i = 0; i < len; i++) {
		if (A[i] < 0){
			temp = A[i];
			for (j = i-1; j >= 0 && A[j] > 0; j--)
				A[j + 1] = A[j];
			A[j+1] = temp;
		}
	}
}