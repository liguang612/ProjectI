#include <iostream>
#include <iomanip>

using namespace std;

int oldPrice(int n) {
    int cost[6] = {1728, 1786, 2074, 2612, 2919, 3015}, level[6] = {50, 50, 100, 100, 100, INT32_MAX}, res = 0;

    for (int i = 0; i < 6; i++)
    {
        if (n > level[i])
        {
            res += level[i] * cost[i];
            n -= level[i];
        }
        else
        {
            res += n * cost[i];
            break;
        }
    }

    return res;
}

int newPrice(int n) {
    int cost[5] = {1728, 2074, 2612, 3111, 3457}, level[5] = {100, 100, 200, 300, INT32_MAX}, res = 0;

    for (int i = 0; i < 5; i++)
    {
        if (n > level[i])
        {
            res += level[i] * cost[i];
            n -= level[i];
        }
        else
        {
            res += n * cost[i];
            break;
        }
    }

    return res;
}

int main() {
    int n;

    cin >> n;
    
    cout << fixed << setprecision(2) << (newPrice(n) - oldPrice(n)) * 1.1;

    return 0;
}