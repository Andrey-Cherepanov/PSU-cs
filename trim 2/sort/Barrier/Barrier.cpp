#include <iostream>

using namespace std;

//Constants
const int array_len = 9;

//Variables
int sorting[array_len];

void display() {
	for (int i = 0; i < array_len; i++) cout << sorting[i] << " ";
	cout << "\n";
}


void qsort(int* A, int len) {

	//����� ���������� ��������
	int barrier = A[len/2];
	//�������� ���������� �� ������ � ����� �������
	int f = 0;
	int l = len - 1;

	do {
		//���� �������� ��� ������
		while (A[f] < barrier) f++;
		while (A[l] > barrier) l--;

		//������ �������� �������
		if (f <= l) {
			swap(A[f], A[l]);
			//cout << f << " " << l << "\n";
			display();

			//��������� ��������� �� ��������� ��������
			f++;
			l--;
		}

	} while (f <= l);

	//����������� ������

	//������ �����
	if (f < len) qsort(&A[f], len-f);

	//����� �����
	if (l > 0) qsort(A, f);
}

int main() {
	for (int i = 0; i < array_len; i++) sorting[i] = rand() % 10;
	display();
	qsort(sorting, array_len);
}