#include <iostream>

using namespace std;

int main() {
    int n, q = 0;
    short temp;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        q += temp;
    }
    
    cout << q;

    return 0;
}