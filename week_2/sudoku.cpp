#include <iostream>
#include <vector>

using namespace std;

short _count = 0;

bool checkRow(vector<short> m, short n, short k) {
    for (short i = k / 9 * 9; i < k / 9 * 9 + 9; i++)
    {
        if (m[i] == n)
        {
            return false;
        }
    }
    return true;
}
bool checkColumn(vector<short> m, short n, short k) {
    for (short i = k % 9; i < 81; i += 9)
    {
        if (i != k && m[i] == n)
        {
            return false;
        }
    }
    return true;
}
bool checkArea(vector<short> m, short n, short k) {
    short row = k / 9, column = k % 9;

    for (short i = row / 3 * 3; i < row / 3 * 3 + 3; i++)
    {
        for (short j = column / 3 * 3; j < column / 3 * 3 + 3; j++)
        {
            if (m[i * 9 + j] == n) {
                return false;
            }
        }
    }
    return true;   
}

void display(vector<short> arr) {
    for (int i = 0; i < 81; i++)
    {
        cout << arr[i] << ' ';
        if (i % 9 == 8)
        {
            cout << endl;
        }
    }
    
}

void solve(vector<short> m, short c[10], int beg) {
    if (beg == 81)
    {
        _count++;
        return;
    }
    
    for (int i = beg; i < 81; i++)
    {
        if (m[i] == 0)
        {
            for (int j = 1; j <= 9; j++)
            {
                if (c[j] < 9 && checkArea(m, j, i) && checkColumn(m, j, i) && checkRow(m, j ,i)) {
                    m[i] = j;
                    c[j]++;

                    solve(m, c, i + 1);

                    c[j]--;
                }
            }
            break;
        }
    }
}

int main() {
    vector<short> sudoku;
    short countdown[10];

    int temp;
    for (int i = 0; i < 10; i++)
    {
        countdown[i] = 0;
    }
    
    for (short i = 0; i < 81; i++)
    {
        cin >> temp;
        sudoku.push_back(temp);
        ++countdown[sudoku[i]];
    }

    solve(sudoku, countdown, 0);

    cout << _count;

    return 0;
}