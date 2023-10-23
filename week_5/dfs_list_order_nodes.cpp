#include <iostream>
#include <stack>
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
    stack<int> st;
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
        st.push(first);
        cout << first << ' ';
        check[first] = false;

        while (!st.empty())
        {
            if (edges[st.top()].empty())
            {
                st.pop();
                continue;
            }

            int temp = *edges[st.top()].begin();

            edges[st.top()].erase(edges[st.top()].begin());
            if (check[temp])
            {
                st.push(temp);
                cout << temp << ' ';
                check[temp] = false; 
            }
        }

        first = check_all(check, node);
    }

    delete[] edges;
    return 0;
}
