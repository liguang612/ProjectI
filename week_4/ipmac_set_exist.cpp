#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, temp;
    unordered_map<int, bool> seq;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        
        if (seq.find(temp) != seq.end())
        {
            cout << 1 << '\n';
            continue;
        }
        seq[temp] = true;
        cout << 0 << '\n';
    }

    return 0;
}