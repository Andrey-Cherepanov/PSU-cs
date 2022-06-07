#include <iostream>
#include <stdlib.h>
using namespace std;


//constatnts
const int rows = 3;
const int V = 4;
const int values[rows][2] = {
    {4000, 4},
    {2500, 1},
    {2000, 3}
};

//variables
int table[rows][V+1];
int max_value;

int main()
{
    for (int i = 0; i < rows; i++) {
        cout << "item " << i + 1 << ": " << values[i][0] << "/" << values[i][1] << ";\n";
    }
    cout << "\n";

    //Заполнеие первой строчки
    for (int i = 0; i <= V; i++) {
        if (values[0][1] > i)
            table[0][i] = 0;
        else
            table[0][i] = values[0][0];
    }
    
    //Заполнение таблицы
    for (int i = 1; i < rows; i++) {
        for (int j = 0; j <= V; j++) {
            if (j - values[i][1] >= 0 && values[i][1] <= V)
                table[i][j] = max(table[i - 1][j], values[i][0] + table[i - 1][j - values[i][1]]);
            else
                table[i][j] = table[i - 1][j];
        }
    }

    //Вывод таблицы
    cout << "\t";
    for (int i = 0; i <= V; i++) cout << i << "\t";
    cout << "\n\n";
    for (int i = 0; i < rows; i++) {
        cout << values[i][0] << "/" << values[i][1] << "\t|";
        for (int j = 0; j <= V; j++) {
            cout << table[i][j] << "\t|";
        }
        cout << "\n";
    }

    cout << "\nMaximum = " << table[rows - 1][V] << "\n";
}
