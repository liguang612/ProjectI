#include <iostream>

using namespace std;

int main() {
    int n, k, arr[1000];

    cin >> k >> n;

    arr[0] = 1;
    for (int i = 1; i < 1000; i++)
    {
        arr[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            arr[j] += arr[j - 1];
            arr[j] %= 1000000007;
        }
    }

    cout << arr[k];

    return 0;
}