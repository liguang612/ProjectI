#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;

    cin >> str;

    if (str.length() != 8)
    {
        cout << "INCORRECT";
        return 0;
    }

    for (int i = 0; i < 8; i++)
    {
        if (i == 2 || i == 5)
        {
            if (str[i] != ':')
            {
                cout << "INCORRECT";
                return 0;
            }
        }
        else {
            if (!isdigit(str[i]))
            {
                cout << "INCORRECT";
                return 0;
            }
            
        }
    }
    
    int h, m, s;

    h = (str[0] - 48) * 10 + (str[1] - 48);
    m = (str[3] - 48) * 10 + (str[4] - 48);
    s = (str[6] - 48) * 10 + (str[7] - 48);

    if (h > 23 || m > 59 || s > 59)
    {
        cout << "INCORRECT";
        return 0;
    }
    

    cout << h * 3600 + m * 60 + s;
    
    return 0;
}