#include <iostream>
using namespace std;

//Constants
const int n = 10;
int arr[n];

void display();
void init_array();
int line_search(int n, int* A, int el);
int bin_search(int n, int* A, int el);
void qsort(int n, int* A);


int main() {
	setlocale(0, "");
	init_array();
	display();
	int el;
	cout << "Введите число для линейного поиска в массиве: "; cin >> el;
	int result = line_search(n, arr, el);
	if (result != -1) cout << "\nИндекс элемента в массиве - " << result << "\n";
	else cout << "\nТакого элемента нет в массиве\n";
	cout << "\n\nВведите число для бинарного поиска в массиве: "; cin >> el;
	result = bin_search(n, arr, el);
	if (result != -1) cout << "\nИндекс элемента в отсортированном массиве - " << result << "\n";
	else cout << "\nТакого элемента нет в массиве\n";

	
}

//Вывод массива
void display() {
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
	cout << "\n";
}

//Заполнение массива
void init_array() {
	for (int i = 0; i < n; i++) arr[i] = rand() % 10;
}


//Линейный поиск
int line_search(int n, int* A, int el)
{
	for (int i = 0; i < n; i++) {
		if (A[i] == el) return i;
	}
	return -1;
}


//Бинарный поиск
int bin_search(int n, int* A, int el)
{	
	int left, right, middle;
	qsort(n, A);
	display();
	if (el <= A[n - 1] && el >= A[0]) {
		left = 0;
		right = n - 1;
		do {
			middle = (left + right) / 2;
			if (A[middle] < el) left = middle + 1;
			else  right = middle - 1;
		} while (left <= right);
		if(A[right+1] == el) return right+1;
	}
	return -1;
}

//Сортировка
void qsort(int n, int* A) {

	//Выбор барьерного элемента
	int barrier = A[n / 2];
	//Создание указателей на начало и конец массива
	int f = 0;
	int l = n - 1;

	do {
		//Ищем элементы для обмена
		while (A[f] < barrier) f++;
		while (A[l] > barrier) l--;

		//Меняем элементы местами
		if (f <= l) {
			swap(A[f], A[l]);

			//Переводим указатели на следующие элементы
			f++;
			l--;
		}

	} while (f <= l);

	//Рекурсивные вызовы

	//Правая часть
	if (f < n) qsort(n - f , &A[f]);

	//Левая часть
	if (l > 0) qsort(f, A);
}