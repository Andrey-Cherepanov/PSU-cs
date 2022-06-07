#include <iostream>

using namespace std;

//init
const int array_len = 9;
int A[array_len];
int C[array_len];

void SortCounting(int* A, int *C, int len) {
	int temp[array_len];
	for (int i = 0; i < len-1; i++) {
		for (int j = i+1; j < len; j++) {
			if (A[i] > A[j])  C[i]++;
			else C[j] ++;
		}
	}
	cout << "Counting array\n";
	for (int i = 0; i < len; i++) cout << C[i] << " ";
	cout << "\n\n";

	for (int i = 0; i < len; i++) temp[C[i]] = A[i];
	for (int i = 0; i < len; i++) A[i] = temp[i];
}

int main() {
	cout << "Start array\n";
	for (int i = 0; i < array_len; i++) {
		A[i] = rand() % 10;
		cout << A[i] << " ";
	}
	cout << "\n\n";

	for (int i = 0; i < array_len; i++) C[i] = 0;

	SortCounting(A, C, array_len);
	cout << "Result array\n";
	for (int i = 0; i < array_len; i++) cout << A[i] << " ";
}