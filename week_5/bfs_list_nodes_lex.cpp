#include <iostream>
#include <queue>
#include <set>

using namespace std;

int check_all(bool* b, int n) {
    for (int i = 1; i < n + 1; i++)
    {
        if (b[i])
        {
            return i;
        }
    }
    return 0; 
}

int main() {
    bool *check;
    int node, edge, a, b;
    queue<int> q;
    set<int>* edges;

    cin >> node >> edge;

    check = new bool[node + 1];
    edges = new set<int>[node + 1];

    for (int i = 0; i < edge; i++)
    {
        cin >> a >> b;
    
        edges[a].insert(b);
        edges[b].insert(a);
    }

    for (int i = 0; i < node + 1; i++)
    {
        check[i] = true;
    }
    
    int first = check_all(check, node);
    while (first != 0)
    {
        q.push(first);
        check[first] = false;

        while (!q.empty())
        {
            for (int i : edges[q.front()])
            {
                if (check[i]) {
                    q.push(i);
                    check[i] = false;
                }
                
                set<int>::iterator temp = edges[i].find(q.front());
                if (temp != edges[i].end())
                {
                    edges[i].erase(edges[i].find(q.front()));
                }
            }

            cout << q.front() << ' ';
            q.pop();
        }

        first = check_all(check, node);
    }

    delete[] edges;
    return 0;
}
