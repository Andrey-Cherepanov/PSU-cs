#include <iostream>
#include <string>
#include <map>

using namespace std;
map<char, int> generate_table(string s);
void print_table(string substring, map<char, int> dict);


int main() {
	setlocale(0, "");
	string text, substring;

	cout << "¬ведите текст: "; cin >> text;
	cout << "¬ведите подстроку: "; cin >> substring;

	map<char, int> table = generate_table(substring);
	print_table(substring, table);

	int substring_len = substring.length(); int text_len = text.length();
	if (substring_len > text_len) {
		cout << "длина подстроки больше длины строки";
		return 0;
	}

	int end = substring_len - 1;
	int i, j;
	bool f = false;
	while (end < text_len) {
		i = end; j = substring_len - 1;

		while (j >= 0 && text[i] == substring[j]) {
			i--; j--;
			f = true;
		}
		if(f){
		i++; j++;
		}; f = false;
		if (j == 0) {
			cout << "вхождение подстроки начинаетс€ с позиции: " << i << "\n";
			end++;
		}
		else if (table.count(text[i]) == 0)
			end += substring_len;
		else
			end += table[text[i]];
	}

}

map<char, int> generate_table(string s)
{
	int len = s.length();
	map<char, int> offset_table;
	for (int i = 0; i < len - 1; i++) offset_table[(char)s[i]] = len - i - 1;
	if (offset_table.count((char)s[len - 1]) == 0) offset_table[(char)s[len - 1]] = len;
	return offset_table;
}

void print_table(string substring, map<char, int> dict)
{
	map <char, int> ::iterator it = dict.begin();
	for (int i = 0; it != dict.end(); it++, i++)
		cout << it->first << " -> " << it->second << "\n";
}
