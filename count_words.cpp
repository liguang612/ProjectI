#include <iostream>
#include <string>

using namespace std;

int main() {
    int q = 0;
    string word;

    while (!feof(stdin))
    {
        cin >> word;
        q++;
    }
    
    cout << q;

    return 0;
}