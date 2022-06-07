#include <iostream>
using namespace std;


const int max_len = 100; int arr[max_len];

void init_array(int* A, int len);
void display(int* A, int len);
int fact(int n);

int main() {
	setlocale(0, "");
	int k, p;
	cout << "¬ведите длину последовательности - k: "; cin >> k;

	init_array(arr, k);
	display(arr, k);
	
	for (int i = 0; i < fact(k) - 1; i++) {
		p = k - 1;
		while (arr[p] == p+1 && p > 0) {
			arr[p] = 1;
			p--;
		}
		arr[p]++;
		display(arr, k);
	};
}


void init_array(int* A, int len) {
	for (int i = 0; i < len; i++) A[i] = 1;
}

void display(int* A, int len) {
	for (int i = 0; i < len; i++) cout << A[i] << " ";
	cout << "\n";
}

int fact(int n) {
	int fact = 1;
	for (int i = 1; i <= n; i++) fact *= i;
	return fact;
}