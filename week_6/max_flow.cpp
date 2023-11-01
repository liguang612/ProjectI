#include <iostream>
#include <vector>

using namespace std;

bool check(int** e, int key, int size, bool in[]) {
    if (in[key])
    {
        return false;
    }
    
    for (int i = 0; i < size; i++)
    {
        if (in[i])
        {
            continue;
        }
        
        if (e[key][i] < 0)
        {
            return false;
        }
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    bool* insource;
    int **edge, m, n, a, b, c, start, finish, min = 0, sum = 0;
    vector<int> source;

    cin >> m >> n >> start >> finish;
    edge = new int*[m];
    insource = new bool[m];
    for (int i = 0; i < m; i++)
    {
        edge[i] = new int[m];
        insource[i] = false;
        for (int j = 0; j < m; j++)
        {
            edge[i][j] = 0;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        --a; --b;
        edge[a][b] = c;
        edge[b][a] = -c;
    }

    --finish;
    source.push_back(--start);
    insource[start] = true;

    for (int i = 0; i < m; i++)
    {
        min += edge[start][i];
    }
    sum = min;

    while (!source.empty())
    {
        start = source[0];
        for (int i = 0; i < m; i++)
        {
            if (i == finish || i == start) continue;
            
            if (edge[start][i] > 0 && check(edge, i, m, insource))
            {
                source.push_back(i);
                insource[i] = true;
            } else continue;

            for (int j = 0; j < m; j++) sum += edge[i][j];

            if (min > sum) min = sum;
        }
        source.erase(source.begin());
    }

    cout << min;

    return 0;
}