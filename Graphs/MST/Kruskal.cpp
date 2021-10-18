#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
const int N = 1e5 + 10, M = 1e3 + 10, OO = 0x3f3f3f3f;


/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

int t, n, m, u, v, c, sorted[M];
int par[N], sz[N], nSets;

struct edge {
    int f, t, c;

    bool operator<(const edge &e) const {
        return c < e.c;
    }
} E[M];

void init(int nNodes) {
    nSets = nNodes;
    iota(par, par + nNodes, 0); //par[i] = i
    fill(sz, sz + nNodes, 1);
}

int find(int u) {
    return par[u] == u ? u : par[u] = find(par[u]);
}

inline bool sameSet(int a, int b) {
    return find(a) == find(b);
}

void join(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return;

    if (sz[u] > sz[v]) swap(u, v);
    nSets--;
    par[u] = v;
    sz[v] += sz[u];
}

ll kruskal() { // O(M*log(N))
    ll total = 0;
    for (int i = 0; i < m; ++i) {
        int idx = sorted[i];
        if (!sameSet(E[idx].f, E[idx].t)) {
            join(E[idx].f, E[idx].t);
            total += E[idx].c;
        }
    }
    return total;
}

int main() {
    FastIO()
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        init(n); // must! clear DSU between each test case
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d", &u, &v, &c);
            E[i] = {--u, --v, c};
            sorted[i] = i;
        }
        sort(sorted, sorted + m, [](const int &a, const int &b) {
            return E[a] < E[b];
        });
        printf("%lld\n", kruskal());
    }


    return 0;
}
