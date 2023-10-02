#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;

    while(!feof(stdin)) {
        getline(cin, str);
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] <= 122 && str[i] >= 97) {
                str[i] -= 32;
            }
        }
        cout << str << endl;
    }

    return 0;
}