#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
const int N = 1e5 + 10, OO = 0x3f3f3f3f;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

int n, m, k;
//vector<vector<int>> adj; // adjacency matrix of graph
const int INF = 1e9; // weight INF means there is no edge

vector<pair<int, ll>> adj[N];

ll dis[N];
int vis[N], vid;

ll prim2(int src = 0) { // O(m log(n))
    ll ret = 0;

    vid++;
    memset(dis, INF, n * sizeof dis[0]);
    priority_queue<pair<ll, int>> q;
    dis[src] = 0;
    q.emplace(0, src);
    while (!q.empty()) {
        int u = q.top().second;
        ll d = -q.top().first;
        q.pop();
        if (d != dis[u]) continue;
        ret += d;
        vis[u] = vid;
        for (auto &e: adj[u]) {
            int v = e.first;
            ll nd = e.second;
            if (nd < dis[v] && vis[v] != vid) {
                dis[v] = nd;
                q.emplace(-nd, v);
            }
        }
    }
    return ret;
}

struct Edge {
    int w = INF, to = -1;
};

ll prim1() { // O(n^2)
    ll total_weight = 0;
    vector<bool> selected(n, false);
    vector<Edge> min_e(n);
    min_e[0].w = 0;

    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w))
                v = j;
        }

        if (min_e[v].w == INF) {
            cout << "No MST!" << endl;
            exit(0);
        }

        selected[v] = true;
        total_weight += min_e[v].w;
        if (min_e[v].to != -1)
            cout << v << " " << min_e[v].to << endl;

        for (int to = 0; to < n; ++to) {
            if (adj[v][to] < min_e[to].w)
                min_e[to] = {adj[v][to], v};
        }
    }

    return total_weight;
}


int main() {
    FastIO()
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }
//    cout << prim1() << "\n";
//    cout << prim2() << "\n";

    return 0;
}
