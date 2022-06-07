#include <iostream>

using namespace std;

//Constants
const int array_len = 9;

//Variables
int sorting[array_len];

void display() {
	for (int i = 0; i < array_len; i++) cout << sorting[i] << " ";
	cout << "\n";
}


void qsort(int* A, int len) {

	//Выбор барьерного элемента
	int barrier = A[len/2];
	//Создание указателей на начало и конец массива
	int f = 0;
	int l = len - 1;

	do {
		//Ищем элементы для обмена
		while (A[f] < barrier) f++;
		while (A[l] > barrier) l--;

		//Меняем элементы местами
		if (f <= l) {
			swap(A[f], A[l]);
			//cout << f << " " << l << "\n";
			display();

			//Переводим указатели на следующие элементы
			f++;
			l--;
		}

	} while (f <= l);

	//Рекурсивные вызовы

	//Правая часть
	if (f < len) qsort(&A[f], len-f);

	//Левая часть
	if (l > 0) qsort(A, f);
}

int main() {
	for (int i = 0; i < array_len; i++) sorting[i] = rand() % 10;
	display();
	qsort(sorting, array_len);
}