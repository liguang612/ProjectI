#include <iostream>
#include <vector>

using namespace std;

bool find(vector<int>q, int k) {
    for (int i = 0; i < q.size(); i++)
    {
        if (q[i] == k)
        {
            return true;
        }
        
    }
    return false;
}

void display(vector<int> q) {
    for (int i = 0; i < q.size(); i++)
    {
        cout << q[i] << ' ';
    }
    cout << endl;
}

void gen(vector<int> q, int n) {
    if (q.size() == n)
    {
        display(q);
        return;
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (!find(q, i))
        {
            q.push_back(i);
            gen(q, n);
            q.pop_back();
        }
    }
}

int main() {
    vector<int> q;
    int n;

    cin >> n;

    gen(q, n);

    return 0;
}