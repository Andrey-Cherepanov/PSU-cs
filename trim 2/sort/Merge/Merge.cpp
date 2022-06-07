#include <iostream>

using namespace std;

//init
const int array_len = 9;
int A[array_len];

void display() {
	for (int i = 0; i < array_len; i++) cout << A[i] << " ";
	cout << "\n";
}

void Merge(int* A, int first, int last) {
	int temp[array_len];
	int left, right, middle;
	left = first; middle = (first + last) / 2; right = middle + 1;
	for (int i = first; i <= last; i++) {
		if ((left <= middle) && ((right > last) || (A[left] < A[right]))) {
			temp[i] = A[left];
			left++;
		}
		else {
			temp[i] = A[right];
			right++;
		}
	}
	for (int i = first; i <= last; i++) A[i] = temp[i];
}

void MergeSort(int* A, int first, int last) {
	if (first < last) {
		MergeSort(A, first, (first + last) / 2);
		MergeSort(A, (first + last) / 2 + 1, last);
		Merge(A, first, last);
		display();
	}

}


int main() {
	for (int i = 0; i < array_len; i++) A[i] = rand() % 10;
	display();
	MergeSort(A, 0, array_len - 1);
}