#include <iostream>
#include <queue>

using namespace std;

struct jugs {
    int a;
    int b;
    int rank;

    jugs() : a(0), b(0), rank(0) {}
    jugs(int a, int b, int rank) : a(a), b(b), rank(rank) {}

    bool operator==(jugs x) {
        return a == x.a && b == x.b;
    }
};

int greatest_common_divisor(int a, int b) {
    int c = min(a, b);
    for (int i = c; i >= 1; i--) {
        if (a % c == 0 && b % c == 0)
        {
            return c;
        }
    }
    return 1;
}

bool find(vector<jugs> his, jugs jug) {
    for (int i = 0; i < his.size(); i++)
    {
        if (his[i] == jug)
        {
            return true;
        }
    }
    return false;
}

int main() {
    int a, b, c, count = 0;
    jugs jug;
    queue<jugs> q;
    vector<jugs> history;

    cin >> a >> b >> c;
    q.push(jug);
    
    while (!q.empty())
    {
        jug = q.front();
        q.pop();
        
        if (find(history, jug)) continue; else {
            history.push_back(jug);
        }
        if (jug.a < a) q.push(jugs(a, jug.b, jug.rank + 1));
        if (q.back().a == c || q.back().b == c) {cout << q.back().rank; return 0;}

        if (jug.b < b) q.push(jugs(jug.a, b, jug.rank + 1));
        if (q.back().a == c || q.back().b == c) {cout << q.back().rank; return 0;}

        if (jug.b > a - jug.a) q.push(jugs(a, jug.b - a + jug.a, jug.rank + 1));
        else q.push(jugs(jug.a + jug.b, 0, jug.rank + 1));
        if (q.back().a == c || q.back().b == c) {cout << q.back().rank; return 0;}

        if (jug.a > b - jug.b) q.push(jugs(jug.a - b + jug.b, b, jug.rank + 1));
        else q.push(jugs(0, jug.a + jug.b, jug.rank + 1));
        if (q.back().a == c || q.back().b == c) {cout << q.back().rank; return 0;}

        if (jug.a > 0) q.push(jugs(0, jug.b, jug.rank + 1));
        else q.push(jugs(0, jug.a + jug.b, jug.rank + 1));
        if (q.back().a == c || q.back().b == c) {cout << q.back().rank; return 0;}
        
        if (jug.b > 0) q.push(jugs(jug.a, 0, jug.rank + 1));
        else q.push(jugs(0, jug.a + jug.b, jug.rank + 1));
        if (q.back().a == c || q.back().b == c) {cout << q.back().rank; return 0;}
    }
    

    return 0;
}