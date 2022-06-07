#include <iostream>

using namespace std;

//init
const int array_len = 9;
int A[array_len];

void display() {
    for (int i = 0; i < array_len; i++) cout << A[i] << " ";
    cout << "\n";
}

void SortChoice(int *A, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < len; j++)
        {
            if (A[j] < A[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(A[i], A[min_index]);
        }
        display();
    }
}

int main() {
    for (int i = 0; i < array_len; i++) A[i] = rand() % 10;
    display();
    SortChoice(A, array_len);
}