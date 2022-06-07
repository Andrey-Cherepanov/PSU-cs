#include <iostream>

using namespace std;

//Init
const int array_len = 9;
int A[array_len];

void display() {
	for (int i = 0; i < array_len; i++) cout << A[i] << " ";
	cout << "\n";
}

void OddEvenSort(int* A, int n) {
	bool isSorted = false;
	int tmp;
	while (!isSorted) {
		isSorted = true;

		for (int i = 0; i < n - 1; i += 2) {
			if (A[i] > A[i + 1]) {
				swap(A[i], A[i + 1]);
				isSorted = 0;
			}
		}
		display();

		for (int i = 1; i < n - 1; i += 2) {
			if (A[i] > A[i + 1]) {
				swap(A[i], A[i + 1]);
				isSorted = 0;
			}
		}
		display();
	}
}

int main() {
	for (int i = 0; i < array_len; i++) A[i] = rand() % 10;
	display();
	OddEvenSort(A, array_len);

}