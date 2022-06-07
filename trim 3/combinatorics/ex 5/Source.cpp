#include <iostream>
using namespace std;


const int max_len = 100;
int arr[max_len];
int last_seq[max_len];

void display(int len, int* A);
void init_arrays(int len, int n, int* A, int* B);
bool is_last(int len, int* A, int* last);

int main() {
	setlocale(0, "");
	int  n, s;
	cout << "¬ведите n: "; cin >> n;
	for (int k = 1; k <= n; k++) {

		init_arrays(k, n, arr, last_seq);
		display(k, arr);

		while (!is_last(k, arr, last_seq)) {
			s = k - 1;
			while (!(arr[s] < n - k + s + 1)) s--;
			arr[s]++;
			for (int i = s + 1; i < k; i++) arr[i] = arr[i - 1] + 1;
			display(k, arr);
		}
	}

}

void display(int len, int* A)
{
	for (int i = 0; i < len; i++) cout << A[i] << " ";
	cout << "\n";
}


void init_arrays(int len, int n, int* A, int* B)
{
	for (int i = 0; i < len; i++) {
		A[i] = (i + 1);
		B[i] = n - len + 1 + i;
	}
}

bool is_last(int len, int* A, int* last)
{
	for (int i = 0; i < len; i++) {
		if (A[i] != last[i]) return false;
	}
	return true;
}
