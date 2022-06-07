#include <iostream>
using namespace std;

//Init
const int array_len = 9;
int A[array_len];


void display()
{
    for (int i = 0; i < array_len; i++) cout << A[i] << " ";
    cout << "\n";
}

void BinaryInsertSort(int* A, int n)
{
    int tmp, left, right, middle;
    for (int i = 1; i < n; i++) {
        if (A[i - 1] > A[i]) {
            tmp = A[i];
            left = 0;
            right = i - 1;
            do {
                middle = (left + right) / 2;
                if (A[middle] < tmp) left = middle + 1;
                else  right = middle - 1;
            } while (left <= right);
            for (int j = i - 1; j >= left; j--)
                A[j + 1] = A[j];
            A[left] = tmp;
        }
        display();
    }
}

void main()
{
    for (int i = 0; i < array_len; i++) A[i] = rand() % 10;
    display();
    BinaryInsertSort(A, array_len);
}