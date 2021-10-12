#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
const int N = 1e5 + 10, OO = 0x3f3f3f3f;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

vector<int> adj[N], ans;
int n, m, vis[N];

void dfs(int u) {
    vis[u] = 1;
    for (auto v: adj[u]) {
        if (!vis[v])
            dfs(v);
    }
    ans.push_back(u);
}

int main() {
    FastIO()
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
    for (int i = 1; i <= n; ++i) {
        if (!vis[i])
            dfs(i);
    }
    for (auto e: ans)
        cout << e << " ";
    cout << "\n";


    return 0;
}
