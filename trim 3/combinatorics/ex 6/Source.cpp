#include <iostream>
using namespace std;

const int max_num = 100; int arr[max_num];

void display(int* A, int len);
void init_array(int* A, int len);

int main() {
	setlocale(0, "");
	int n, k, sum, s;
	cout << "¬ведите n: "; cin >> n;
	k = n;
	init_array(arr, k);
	display(arr, k);

	while (k > 1) {
		s = k - 2;
		while (s > 0 && !(arr[s - 1] > arr[s])) s--;
		arr[s]++;
		sum = 0;
		for (int i = s + 1; i < k; i++) sum += arr[i];
		for (int i = 1; i <= sum - 1; i++) arr[s + i] = 1;
		k = s + sum;
		display(arr, k);
	}

}

void display(int* A, int len)
{
	for (int i = 0; i < len - 1; i++) cout << A[i] << "+";
	cout << A[len-1] << "\n";
}

void init_array(int* A, int len)
{
	for (int i = 0; i < len; i++) A[i] = 1;
}


