#include <iostream>

using namespace std;

//init
const int array_len = 9;
int A[array_len];

void display() {
	for (int i = 0; i < array_len; i++) cout << A[i] << " ";
	cout << "\n";
}

void ChangeSort(int *A, int len) {
	int tmp;
	bool sorted;
	do {
		sorted = false;
		for (int i = 0; i < len - 1; i++) {
			if (A[i] > A[i + 1]) {
				tmp = A[i + 1];
				A[i + 1] = A[i];
				A[i] = tmp;
				sorted = true;
			}

		}
		display();
	} while (sorted);
}

int main() {
	for (int i = 0; i < array_len; i++) A[i] = rand() % 10;
	display();
	ChangeSort(A, array_len);
}