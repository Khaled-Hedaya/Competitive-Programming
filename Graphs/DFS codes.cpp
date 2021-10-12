#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
const int N = 1e3 + 10, OO = 0x3f3f3f3f;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

vector<int> adj[N];
int vis[N], n, m;
vector<int> ans;

// if we defintely sure that the given graph is tree, we can use parent variable instead of visited array
void dfsOnTree(int u, int p) {
    for (auto v: adj[u]) {
        if (v == p) continue;
//        depth[v] = depth[u] + 1;
        dfsOnTree(v, u);
    }
}

// standard dfs code
void dfs(int u) {
    vis[u] = 1;
    for (auto v: adj[u]) {
        if (vis[v])
            continue;
        dfs(v);
    }
}

int main() {
//    FastIO()
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
//    dfsOnTree(3, -1);

    dfs(3);
    for (int i = 0; i < n; ++i) {
        if (vis[i]) cout << i << " ";
    }
    cout << "\n";
    return 0;
}
