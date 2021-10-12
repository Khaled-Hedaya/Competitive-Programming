#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, OO = 0x3f3f3f3f;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

vector<int> adj[N];
int cntConnectedComps; // initially = 0
int vis[N];

// basic dfs code
/*
int dfs1(int src) {
    vis[src] = 1;
    for (auto ch: adj[src]) {
        if (!vis[ch])
            dfs1(ch);
    }
}
*/

// ###################################

// count number of connected components in (Undirected graph)
/*
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int node = 0; node < n; ++node) { // assume that all vertices in range [0 , n-1]
        if (!vis[node]) {
            cntConnectedComps++;
            dfs1(node);
        }
    }
    cout << "Number of connected components = " << cntConnectedComps << "\n";
}
*/

// ###########################

// flood fill - coloring connected components
/*
void floodFill(int sr, int sc) {
 // assume that we have an implicit graph in a form of 2D grid
 // and we want to traverse it, cells represent vertices and all 8 direction's neighbours represents edges
    if (sr < 0 || sr >= rows || sc < 0 || sc >= cols)
        return;
    // other invalid conditions written here or in above condition
    for (int d = 0; d < 8; ++d) {
        int nr = sr + dx[d];
        int nc = sc + dy[d];
        if (valid(nr, nc) && !vis[nr][nc])
            floodFill(nr, nc);
    }
}
*/
// ###########################

// Topological sort (DAG - Directed Acyclic graph)
/*
    vector < int > topo; // vector for storing topo order
    void dfs2(int src){
        vis[src] = 1;
        for(auto ch : adj[src]){
            if(!vis[ch])
                dfs2(ch);
        }
        topo.push_back(src);
    }
*/

// #############################

// modified BFS for Bipartite Graph Check (can be colored using two colors)
// Can also be done using DFS!
/*
    bool isBipartite(int src){
        queue < int > q;
        memset(col , OO , sizeof col);
        col[src] = 0;
        q.push(src);
        while(!q.empty()){
            int p = q.front();
            q.pop();
            for(auto ch : adj[p]){
                if(col[ch] == OO){
                    col[ch] = 1 - col[p];
                    q.push(ch);
                }
                else if(col[ch] == col[p]){
                    return 0;
                }
            }
        }
        return 1;
    }
*/

// ##########################

// Egdes classification on (Undirected Graph)
// - Tree edge -> (from explored vertex to unvisited vertex)
// - Forward edge -> (from explored vertex to visited vertex)
// - Backward edge -> (from explored vertex to explored vertex)
/*
void graphCheck(int u) {
    dfs_num[u] = EXPLORED;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == UNVISITED) {
            dfs_parent[v.first] = u;
            graphCheck(v.first);
        }
        else if (dfs_num[v.first] == EXPLORED) {
            if (v.first == dfs_parent[u])
                printf(" Two ways (%d, %d)-(%d, %d)\n", u, v.first, v.first, u);
            else
                printf(" Back Edge (%d, %d) (Cycle)\n", u, v.first);
        }
        else if (dfs_num[v.first] == VISITED)
            printf(" Forward/Cross Edge (%d, %d)\n", u, v.first);
    }
    dfs_num[u] = VISITED;
}
*/

// ##################################

int main() {


    return 0;
}
