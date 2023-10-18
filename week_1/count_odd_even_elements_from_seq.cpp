#include <iostream>

using namespace std;

int main() {
    int n, odd = 0, even = 0, temp;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;

        if (temp % 2)
        {
            odd++;
        } else {
            even++;
        }
    }
    
    cout << odd << ' ' << even;

    return 0;
}