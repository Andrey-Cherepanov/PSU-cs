#include <iostream>
#include <string>

using namespace std;
const int q = 47;

int hash_function(string line, int x);

int main() {
    setlocale(0, "");
    int x = rand() % q;
    string line, text;
    cout << "������� �����: "; cin >> text;
    cout << "������ ���������: "; cin >> line;
    int hash_line = hash_function(line, x);

    int len_line = line.length();
    int len_text = text.length();
    string temp = ""; int hash;
    bool is_equal = false;
    int j, k;
    for (int i = 0; i < len_text - len_line + 1; i++) {
        temp.clear();
        temp.append(text, i, len_line);
        hash = hash_function(temp,x);
        //cout << hash << "\n";
        if (hash == hash_line) {
            is_equal = true;
            for (int j = 0; j < len_line; j++) {
                if (line[j] != temp[j])
                    is_equal = false;
            }
            if (is_equal) cout << "��������� ��������� ���������� � ������� " << i << "\n";
        }
    }
}

int hash_function(string line, int x) {
    int m = line.length();
    int hash = 0;
    for (int i = 0; i < line.length(); i++)
        hash += (int)((char)line[i]) * pow(x, m - (i + 1));
    hash %= q;
    return hash;
}