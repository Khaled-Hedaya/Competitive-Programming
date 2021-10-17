#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
typedef pair<int, int> pii;
const int N = 1e5 + 10, OO = 0x3f3f3f3f;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

int n, m, dis[N];
vector<pii> adj[N];

void dijkstra(int src) { //O( (V+E)log(V) )
    priority_queue<pii, vector<pii>, greater<>> q;
    memset(dis, OO, n * sizeof dis[0]);
    dis[src] = 0;
    q.emplace(0, src);
    while (!q.empty()) {
        int d = q.top().first;
        int u = q.top().second;
        q.pop();
        if (d != dis[u]) continue;
        for (auto e: adj[u]) {
            int v = e.first, c = e.second; // vertex , cost
            int nd = dis[u] + c;
            if (nd < dis[v]) {
                dis[v] = nd;
                q.emplace(nd, v);
            }
        }
    }
}

int main() {
    FastIO()
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int v, cst;
        cin >> v >> cst;
        adj[i].emplace_back(--v, cst);
    }
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        dijkstra(u);
        cout << dis[v] << endl;
    }


    return 0;
}
