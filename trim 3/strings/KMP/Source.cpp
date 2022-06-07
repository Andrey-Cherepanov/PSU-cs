#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> prefix_function(string s);

int main() {
	setlocale(0, "");
	string t, s;
	cout << "Введите текст: ";  cin >> t;
	cout << "Введите подстроку: "; cin >> s;
	int len_t, len_s; len_t = t.length(); len_s = s.length();
	string line = s + "#" + t;
	//cout << line;

	int f = 0;
	vector<int> pi = prefix_function(line);
	for (int i = len_s + 1; i < len_s + len_t + 1; i++) {
		if (pi[i] == len_s) {
			cout << "Вхождение подстроки в текст начинается с позиции " << i - 2 * len_s << "\n";
			f++;
		}
	}
	if (f == 0) cout << "Подстрока не входит в данный текст";
	//for (int i = 0; i < pi.size(); i++) cout << pi[i] << " ";

}

vector<int> prefix_function(string s)
{
	int n = (int)s.length();
	vector<int> pi(n);
	for (int i = 1; i < n; i++) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}
