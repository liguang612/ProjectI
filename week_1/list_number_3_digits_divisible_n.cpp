#include <iostream>

using namespace std;

int main() {
    int n, res;

    cin >> n;

    res = (100 / n + (100 % n == 0 ? 0 : 1)) * n;

    while (res < 1000)
    {
        cout << res << ' ';
        res += n;
    }
    
    return 0;
}