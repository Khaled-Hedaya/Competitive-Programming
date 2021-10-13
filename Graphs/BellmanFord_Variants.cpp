#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
const int N = 1e5 + 10, OO = 0x3f3f3f3f;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

struct edge {
    int from, to, cost;
} edges[N];


int dis[N], n, m, q;
vector<pair<int, int>> adj[N];

// a graph of 'n' nodes and 'm' edges has a maximum path of 'n-1' edges,
// so we need to relax all edges 'n-1' times
bool
bellman_1(int src) { // -> check if the graph has negative cycle or not, regardless the path from 'src' to 'destination'
    memset(dis, OO, sizeof dis);
    dis[src] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int e = 0; e < m; e++) { // 'm' is the number of edges
            int u = edges[e].from, v = edges[e].to, c = edges[e].cost;
            if (dis[u] + c < dis[v]) {
                if (i == n) return 0;
                dis[v] = dis[u] + c;
            }
        }
    }
    return 1;
}

int inQ[N], vid;

// if the the path from 'src' to 'snk' not affected from the negative cycle we continue normally
bool bellman_2(int src, int snk) { // take 'source' and 'destination'
    ++vid;
    memset(dis, OO, n * sizeof dis[0]);
    queue<int> changed;

    dis[src] = 0;
    inQ[src] = vid, changed.push(src);

    for (int k = 0; k <= 2 * n; ++k) {
        int sz = (int) changed.size();
        while (sz--) {
            int u = changed.front();
            changed.pop();
            inQ[u] = 0;

            for (auto e: adj[u]) {
                int v = e.first;
                int c = e.second;
                if (dis[u] != OO && dis[u] + c < dis[v]) {
                    if (k >= n && v == snk) return false;
                    dis[v] = dis[u] + c;
                    if (inQ[v] != vid) inQ[v] = vid, changed.push(v);
                }
            }
        }
    }

    return true;
}


int main() {
    FastIO()
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif

    while (cin >> n >> m >> q, n || m || q) {
        for (int i = 0; i < n; ++i) {
            adj[i].clear();
        }
        for (int i = 0; i < m; ++i) {
            int u, v, c;
            cin >> u >> v >> c;
            //edges[i] = {u, v, c};
            adj[u].emplace_back(v, c);
        }
        for (int i = 0; i < q; ++i) {
            int u, v;
            cin >> u >> v;
            if (!bellman_2(u, v)) cout << "-Infinity\n";
            else {
                if (dis[v] >= OO) cout << "Impossible\n";
                else cout << dis[v] << endl;
            }
        }
        cout << endl;
    }


    return 0;
}
