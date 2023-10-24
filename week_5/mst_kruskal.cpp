#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<int> parent;

struct edge {
    int begin, end, weight;

    edge(int begin, int end, int weight) : begin(begin), end(end), weight(weight) {}

    bool operator<(const edge& other) const {
        if (weight != other.weight)
        {
            return weight < other.weight;
        }
        if (begin != other.begin)
        {
            return begin < other.begin;
        }
        return end < other.end;
    }
};

int find(int u) {
    if (u == parent[u])
    {
        return u;
    }
    return parent[u] = find(parent[u]);
}
bool union_partition(int a, int b) {
    int _a = find(a), _b = find(b);
    
    if (_a != _b)
    {
        parent[_a] = _b;
    }

    return _a == _b;
}

int main() {
    freopen("input.txt", "r", stdin);

    int n, m, weight = 0, a, b, c;
    set<edge> edges;

    cin.sync_with_stdio(0); cin.tie(0);
    cout.sync_with_stdio(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n + 1; i++)
    {
        parent.push_back(i);
    }
    
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        edges.insert(edge(a, b, c));
    }
    for (edge i : edges)
    {
        if (!union_partition(i.begin, i.end))
        {
            weight += i.weight;
        }
    }

    cout << weight;

    return 0;
}