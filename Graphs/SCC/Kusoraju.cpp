#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
const int OO = 0x3f3f3f3f;


vector<int> adj[150], adjR[150];
stack<int> nodes;
int compId[150], vis[150], vid, n, m, cntComp;
int notSrc[150], notSnk[150];

void dfs1(int u) {
    if (vis[u] == vid) return;
    vis[u] = vid;
    for (auto v: adj[u]) {
        dfs1(v);
    }
    nodes.push(u);
}

void dfs2(int u, int id) {
    if (vis[u] == vid) return;
    vis[u] = vid;
    compId[u] = id;
    for (auto v: adjR[u]) {
        dfs2(v, id);
    }
}


void Kusoraju() {
    ++vid;
    for (int i = 0; i < n; ++i) {
        if (vis[i] != vid) {
            dfs1(i);
        }
    }
    ++vid;
    cntComp = 0;
    while (!nodes.empty()) {
        int u = nodes.top();
        nodes.pop();
        if (vis[u] == vid) continue;
        dfs2(u, cntComp++);
    }
    for (int u = 0; u < n; ++u) {
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i];
            if (compId[u] == compId[v])
                continue;
            notSrc[compId[v]] = vid;
            notSnk[compId[u]] = vid;
        }
    }

}


int main() {
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


    cin >> n;
    for (int i = 0; i < n; ++i) {
        while (cin >> m, m) {
            --m;
            adj[i].push_back(m);
            adjR[m].push_back(i);
        }
    }

    Kusoraju();

    for (int i = 0; i < n; ++i) { // all nodes have the same id are on the same SCC
        cout << "Node = " << i << ", has compId = " << compId[i] << "\n";
    }

//    int cntSrc = cntComp - count(notSrc, notSrc + cntComp, vid);
//    int cntSnk = cntComp - count(notSnk, notSnk + cntComp, vid);
//
//
//    cout << cntSrc << "\n";
//    cout << (cntComp == 1 ? 0 : max(cntSrc, cntSnk)) << "\n";


    return 0;
}
