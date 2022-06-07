#include <iostream>
using namespace std;

int main() {
	setlocale(0, "");
	int x, n;
	cout << "¬ведите аргумент фунции - x: "; cin >> x;
	cout << "¬ведите количество слагаемых - n: "; cin >> n;

	double f = 0;
	int fact = 1;
	for (int i = 0; i <= n; i++) {
		if (i > 1) fact *= i;
		f += pow(-1, i) * pow(x, 2 * i) / fact;
	}
	f = round(f * 1000) / 1000;
	cout << "\nexp(-" << pow(x, 2) << ") = " << f;

}