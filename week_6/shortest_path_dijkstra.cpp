#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;

    vector<pii>* edges = new vector<pii>[m + 1];
    for (int i = 0; i < n; i++)
    {
        int begin, end, weight;
        cin >> begin >> end >> weight;
        edges[begin].push_back(make_pair(end, weight));
    }

    int start, end;
    cin >> start >> end;

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

    cout << (dist[end] != INT_MAX ? dist[end] : -1);

    return 0;
}
