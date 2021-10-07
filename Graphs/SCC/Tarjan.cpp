#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;


typedef long long ll;
const int OO = 0x3f3f3f3f;
#define PI acos(-1)
#define clr(arr, val) memset(arr, val, sizeof(arr))
#define loop(i, n) for (int i = 0; i < int(n); i++)
#define rloop(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define xloop(i, a, b) for (int i = int(a); i <= int(b); i++)
#define ALL(v) ((v).begin()), ((v).end())
#define SZ(v) ((int)((v).size()))
#define EPS 1e-9
typedef long long ll;
int dx[] = {1, 0, -1, 0}; // {down , right , up , left}
int dy[] = {0, 1, 0, -1}; //4 Direction
//int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
//int dy[] = {0, 1, 1, 1, 0, -1, -1, -1}; //8 direction
//int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
//int dy[] = {1, 2, 2, 1, -1, -2, -2, -1}; //Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

//-- "كلٌّ من يسعى لابد يصل .. كلٌّ من يسعى مضمون له الوصول" --//


vector<int> adj[150];
stack<int> nodes;
int compId[150], vis[150], vid, n, m, cntComp;
int notSrc[150], notSnk[150], dfsTime[150], dfsLow[150], curTime;

void dfs(int u) {
    compId[u] = -1;
    dfsTime[u] = dfsLow[u] = curTime++;
    vis[u] = vid;
    nodes.push(u);

    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (vis[v] != vid) {
            dfs(v);
            dfsLow[u] = min(dfsLow[u], dfsLow[v]);
        } else if (compId[v] == -1) {
            dfsLow[u] = min(dfsLow[u], dfsLow[v]);
        }

    }
    if (dfsLow[u] == dfsTime[u]) {
        int x;
        do {
            x = nodes.top();
            nodes.pop();
            compId[x] = cntComp;
        } while (x != u);
        cntComp++;
    }

}


void Tarjan() {
    curTime = cntComp = 0;
    ++vid;
    for (int i = 0; i < n; ++i) {
        if (vis[i] != vid) {
            dfs(i);
        }
    }

    for (int u = 0; u < n; ++u) {
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i];
            if (compId[u] == compId[v])
                continue;
            // this two loops passes only through edges that connects two different SCCs, and neglect edges on the same SCC
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
        }
    }

    Tarjan();

//    int cntSrc = cntComp - count(notSrc , notSrc + cntComp , vid);
//    int cntSnk = cntComp - count(notSnk , notSnk + cntComp , vid);
//
//
//    cout << cntSrc << "\n";
//    cout << (cntComp == 1 ? 0 : max(cntSrc , cntSnk)) << "\n";





    return 0;
}
