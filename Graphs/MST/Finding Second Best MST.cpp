#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, OO = 0x3f3f3f3f;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

int sorted[205];

struct edge {
    int c, f, t;

    bool operator<(const edge &e) const {
        return c < e.c;
    }
} E[205];

struct DSU {
    int parent[105], sz[105], nSets;

    void init(int n) {
        iota(parent, parent + n, 0);
        fill(sz, sz + n, 1);
        nSets = n;
    }

    int findparent(int u) {
        return u == parent[u] ? u : parent[u] = findparent(parent[u]);
    }

    bool sameSet(int a, int b) {
        return findparent(a) == findparent(b);
    }

    void join(int a, int b) {
        a = findparent(a);
        b = findparent(b);
        if (a == b) return;
        if (sz[a] > sz[b])
            swap(a, b);
        sz[b] += sz[a];
        parent[a] = b;
        nSets--;
    }

};

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    DSU d;
    d.init(n);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        --a, --b;
        E[i] = {c, a, b};
        sorted[i] = i;
    }
    sort(sorted, sorted + m, [](const int &a, const int &b) {
        return E[a] < E[b];
    });
    vector<int> MSTedges;
    for (int i = 0; i < m; ++i) {
        int idx = sorted[i];
        int f = E[idx].f;
        int t = E[idx].t;
        if (d.sameSet(f, t))
            continue;
        MSTedges.push_back(idx);
        d.join(f, t);
    }
    if (d.nSets != 1) {
        puts("No way");
        return;
    }
    vector<int> closed(m, 0);
    int mn = OO;
    for (auto e: MSTedges) {
        closed[e] = 1;
        d.init(n);
        int cost = 0;
        for (int i = 0; i < m; ++i) {
            int idx = sorted[i];
            if (closed[idx])
                continue;
            int f = E[idx].f;
            int t = E[idx].t;
            int c = E[idx].c;
            if (d.sameSet(f, t))
                continue;
            d.join(f, t);
            cost += c;
        }
        if (d.nSets == 1) { // if tree found ?
            mn = min(mn, cost); // try to minimize the second best spanning tree cost
        }
        closed[e] = 0;
    }
    if (mn == OO) puts("No second way");
    else printf("%d\n", mn);
}

int main() {

#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif

    int tc = 1;
    scanf("%d", &tc);
    for (int i = 1; i <= tc; i++) {
        printf("Case #%d : ", i);
        solve();
#ifdef ONPC
        puts("------------------");
#endif
    }

    return 0;
}
