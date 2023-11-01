#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

int m, n;
vector<pii>* edges;

int shortest_path(int start, int end) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(m + 1, INT_MAX);
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto& edge : edges[u])
        {
            int v = edge.first;
            int weight = edge.second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return (dist[end] != INT_MAX ? dist[end] : -1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;
    edges = new vector<pii>[m + 1];

    for (int i = 0; i < n; i++)
    {
        int begin, end, weight;
        cin >> begin >> end >> weight;
        edges[begin].push_back(make_pair(end, weight));
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << shortest_path(i, j) << ' ';
        }
        cout << '\n';
    }

    return 0;
}
