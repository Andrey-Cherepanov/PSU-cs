#include <iostream>
#include <string>

using namespace std;

const int q = 47;

int hash_function(string line);

int main() {
    setlocale(0, "");
    string line, text;
    cout << "Введите текст: "; cin >> text;
    cout << "Ввеите подстроку: "; cin >> line;
    int hash_line = hash_function(line);

    int len_line = line.length();
    int len_text = text.length();
    string temp; int hash;
    bool is_equal;
    for (int i = 0; i < len_text - len_line + 1; i++) {
        temp.clear();
        temp.append(text, i, len_line);
        hash = hash_function(temp);
        if (hash == hash_line) {
            is_equal = true;
            for (int j = 0; j < len_line; j++) {
                if (line[j] != temp[j])
                    is_equal = false;
            }
            if (is_equal) cout << "Вхождение подстроки начинается с позиции " << i << "\n";
        }
    }
}

int hash_function(string line) {
    int hash = 0;
    for (int i = 0; i < line.length(); i++) hash += (int)line[i];
    return hash;
}
