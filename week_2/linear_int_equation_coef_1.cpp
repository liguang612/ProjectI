#include <iostream>
#include <vector>

using namespace std;

void display(vector<int> vt) {
    for (int i = 0; i < vt.size(); i++)
    {
        cout << vt[i] << ' ';
    }
    cout << endl;
}

void gen(vector<int> vt, int n, int m) {
    if (n == 0 && m == 0)
    {
        display(vt);
        return;
    }
    if (n == 0 || m == 0)
    {
        return;
    }
    
    
    for (int i = 1; i <= m - n + 1; i++)
    {
        vt.push_back(i);
        gen(vt, n - 1, m - i);
        vt.pop_back();
    }
}

int main() {
    int n, m;
    vector<int> vt;

    cin >> n >> m;

    gen(vt, n, m);

    return 0;
}