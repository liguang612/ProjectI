#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct edge {
    int u, v, c;
    edge(int _u, int _v, int _c): u(_u), v(_v), c(_c) {};
};

struct dsu {
    vector<int> par;

    void init(int n) {
        par.resize(n + 5, 0);
        for (int i = 1; i <= n; i++) par[i] = i;
    }

    int find(int u) {
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    }

    bool join(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return false;
        par[v] = u;
        return true;
    }
} dsu;

int n, m, weight = 0;
vector<edge> edges;

int main() {
    // freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back({u, v, c});
    }

    dsu.init(n);

    sort(edges.begin(), edges.end(), [](edge & x, edge & y) {
        return x.c < y.c;
    });

    for (auto e : edges) {
        if (!dsu.join(e.u, e.v)) continue;

        weight += e.c;
    }

    cout << weight << '\n';

    return 0;
}