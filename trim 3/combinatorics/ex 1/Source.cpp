#include <iostream>
using namespace std;
const int max_len = 100; int arr[max_len];

void init_array(int* A, int len);
void display(int* A, int len);

int main() {
	setlocale(0, "");
	int n, k, p;
	cout << "¬ведите длину последовательности - k: "; cin >> k;
	cout << "¬ведите максимальное число в последовательности - n: "; cin >> n;

	init_array(arr, k);
	display(arr, k);

	for (int i = 0; i < pow(n, k) - 1; i++) {
		p = k - 1;
		while (arr[p] == n && p > 0) {
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