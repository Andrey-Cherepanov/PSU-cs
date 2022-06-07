#include <iostream>

using namespace std;

//Initialisation
const int array_len = 9;
int A[array_len];

void display() {
	for (int i = 0; i < array_len; i++) cout << A[i] << " ";
	cout << "\n";
}

void ShellSort(int* A, int n) {
	int i, j, step;
	int tmp;
	for (step = n / 2; step > 0; step /= 2) {
        for (i = step; i < n; i++)
        {
            tmp = A[i];
            for (j = i; j >= step && tmp < A[j - step]; j -= step)
            {
                A[j] = A[j - step];
            }
            A[j] = tmp;
        }
        //Вывод
        cout << " \nstep = " << step << ":\n";
        display();
	}
}

int main() {
	for (int i = 0; i < array_len; i++) A[i] = rand() % 10;
	display();
	ShellSort(A, array_len);
}