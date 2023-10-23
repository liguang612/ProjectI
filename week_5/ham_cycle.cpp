#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);

    bool check;
    int num, n, m, a, b;

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> n >> m;
        
        int* level = new int[n + 1];

        for (int j = 0; j < n + 1; j++)
        {
            level[j] = 0;
        }
        
        for (int j = 0; j < m; j++)
        {
            cin >> a >> b;
            level[a]++;
            level[b]++;
        }

        check = true;
        int _min = floor(n / 2.0);
        for (int j = 1; j <= n; j++)
        {
            if (level[j] < _min)
            {
                check = false;
                break;
            }
        }

        cout << check << endl;

        delete[] level;
    }
    
    return 0;
}