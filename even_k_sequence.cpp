#include <iostream>

using namespace std;

int main() {
    int n, k, *arr, sum = 0, q = 0;

    cin >> n >> k;

    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    

    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }

    if (sum % 2 == 0)
    {
        q++;
    }
    for (int i = k; i < n; i++)
    {
        sum += arr[i]; sum -= arr[i - k];
        if (sum % 2 == 0)
        {
            ++q;
        }
    }
    
    cout << q;

    return 0;
}