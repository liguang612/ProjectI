#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cout.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int m, n, temp, count = 0;
    unordered_set<int> seq;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;

        if (seq.find(m - temp) != seq.end()) {
            ++count;
        } else {
            seq.insert(temp);
        }
    }

    cout << count << endl;
    
    return 0;
}