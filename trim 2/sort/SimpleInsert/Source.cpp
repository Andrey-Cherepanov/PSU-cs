#include <iostream>

using namespace std;

const int array_len = 9;
int A[array_len];

void display() {
	for (int i = 0; i < array_len; i++) cout << A[i] << " ";
	cout << "\n";
}

void SortInsert(int* A, int len) {
	int tmp = 0;
	int j;
	for (int i = 1; i < len; i++)
	{
		tmp = A[i];
		for (j = i - 1; j >= 0 && A[j] > tmp; j--)
			A[j + 1] = A[j];

		A[j + 1] = tmp;
		display();
	}
}

int main() {
	for (int i = 0; i < array_len; i++) A[i] = rand() % 10;
	display();
	SortInsert(A, array_len);
}