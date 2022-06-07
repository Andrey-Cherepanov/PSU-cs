#include <iostream>
using namespace std;

const int max_len = 100;
int arr[max_len];

void display(int len, int* A);
void init_array(int len, int* A);
int fact(int n);
void reverse_array(int len, int* A);

int main() {
	setlocale(0, "");
	int n, k, t;
	cout << "¬ведите n: "; cin >> n;
	init_array(n, arr);
	display(n, arr);

	for (int i = 0; i < fact(n) - 1; i++) {
		k = n - 2;
		while (arr[k] > arr[k + 1]) k--;
		t = k + 1;
		while (t<n - 1 && arr[t + 1] > arr[k]) t++;
		swap(arr[t], arr[k]);
		reverse_array(n - (k + 1), &arr[k+1]);
		display(n, arr);
	}

}

void display(int len, int* A)
{
	for (int i = 0; i < len; i++) cout << A[i] << " ";
	cout << "\n";
}

void init_array(int len, int* A)
{
	for (int i = 0; i < len; i++) A[i] = i + 1;
}

int fact(int n)
{
	int fact = 1;
	for (int i = 1; i <= n; i++) fact *= i;
	return fact;
}

void reverse_array(int len, int* A)
{
	for (int i = 0; i < len / 2; i++) swap(A[i], A[len - i - 1]);
}
