#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
const int N = 1e5 + 10, OO = 0x3f3f3f3f;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

int sz[N], par[N], nComps;

void init(int n) {
    iota(par, par + n + 1, 0);
    fill(sz, sz + n + 1, 1);
    nComps = n; // initially number of components equals to number of elements
}

int findParent(int u) {
    return (par[u] == u ? u : par[u] = findParent(par[u]));
}

bool sameSet(int a, int b) {
    return findParent(a) == findParent(b);
}

void join(int a, int b) {
    a = findParent(a), b = findParent(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b]; // 'a' is Here the greatest in size
    par[b] = a;     // join the small tree 'b' in the bigger one 'a'
    --nComps;
}


int main() {
    FastIO()
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif
    int n, e;
    cin >> n >> e;
    // don't forget to init between test cases!
    init(n);

    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        if (sameSet(a, b)) {
            cout << a << " and " << b << " are in the same component!\n";
        } else {
            join(a, b); // make 'a' and 'b' in the same component
        }
    }


    return 0;
}
