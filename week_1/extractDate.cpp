#include <iostream>

using namespace std;

int main() {
    string str;

    cin >> str;

    if (str.length() != 10) {
        cout << "INCORRECT";
        return 0;
    }
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
        {
            if (str[i] != '-')
            {
                cout << "INCORRECT";
                return 0;
            } else {
                str[i] = ' ';
            }
        } else {
            if (!isdigit(str[i]))
            {
                cout << "INCORRECT";
                return 0;
            }
            
        }
    }

    int y = 0, m = 0, d = 0;

    y = (str[0] - 48) * 1000 + (str[1] - 48) * 100 + (str[2] - 48) * 10 + (str[3] - 48);
    m = (str[5] - 48) * 10 + (str[6] - 48);
    d = (str[8] - 48) * 10 + (str[9] - 48);
    
    if (m < 1 || m > 12)
    {
        cout << "INCORRECT";
        return 0;
    }
    switch (m)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        if (d < 1 || d > 31)
        {
            
            cout << "INCORRECT";
            return 0;
        }
        break;
    case 4: case 6: case 9: case 11:
        if (d < 1 || d > 30)
        {
            cout << "INCORRECT";
            return 0;
        }
        break;
    case 2:
        if (d < 1 || d > (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0) ? 29 : 28))
        {
            cout << "INCORRECT";
            return 0;
        }
    default:
        break;
    }

    cout << y << ' ' << m << ' ' << d;

    return 0;
}