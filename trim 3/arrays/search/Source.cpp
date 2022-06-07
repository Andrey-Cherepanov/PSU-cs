#include <iostream>
using namespace std;

//Constants
const int n = 10;
int arr[n];

void display();
void init_array();
int line_search(int n, int* A, int el);
int bin_search(int n, int* A, int el);
void qsort(int n, int* A);


int main() {
	setlocale(0, "");
	init_array();
	display();
	int el;
	cout << "������� ����� ��� ��������� ������ � �������: "; cin >> el;
	int result = line_search(n, arr, el);
	if (result != -1) cout << "\n������ �������� � ������� - " << result << "\n";
	else cout << "\n������ �������� ��� � �������\n";
	cout << "\n\n������� ����� ��� ��������� ������ � �������: "; cin >> el;
	result = bin_search(n, arr, el);
	if (result != -1) cout << "\n������ �������� � ��������������� ������� - " << result << "\n";
	else cout << "\n������ �������� ��� � �������\n";

	
}

//����� �������
void display() {
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
	cout << "\n";
}

//���������� �������
void init_array() {
	for (int i = 0; i < n; i++) arr[i] = rand() % 10;
}


//�������� �����
int line_search(int n, int* A, int el)
{
	for (int i = 0; i < n; i++) {
		if (A[i] == el) return i;
	}
	return -1;
}


//�������� �����
int bin_search(int n, int* A, int el)
{	
	int left, right, middle;
	qsort(n, A);
	display();
	if (el <= A[n - 1] && el >= A[0]) {
		left = 0;
		right = n - 1;
		do {
			middle = (left + right) / 2;
			if (A[middle] < el) left = middle + 1;
			else  right = middle - 1;
		} while (left <= right);
		if(A[right+1] == el) return right+1;
	}
	return -1;
}

//����������
void qsort(int n, int* A) {

	//����� ���������� ��������
	int barrier = A[n / 2];
	//�������� ���������� �� ������ � ����� �������
	int f = 0;
	int l = n - 1;

	do {
		//���� �������� ��� ������
		while (A[f] < barrier) f++;
		while (A[l] > barrier) l--;

		//������ �������� �������
		if (f <= l) {
			swap(A[f], A[l]);

			//��������� ��������� �� ��������� ��������
			f++;
			l--;
		}

	} while (f <= l);

	//����������� ������

	//������ �����
	if (f < n) qsort(n - f , &A[f]);

	//����� �����
	if (l > 0) qsort(f, A);
}