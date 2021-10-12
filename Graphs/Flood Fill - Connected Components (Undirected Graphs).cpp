#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
const int N = 1e5 + 10, OO = 0x3f3f3f3f;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

int n, m, rx, ry, cx, cy, u, v, num;
string grid[N];
int dis[N][N], vis[N];
vector<int> adj[N];
int dx[] = {1, -1, 0, 0};            //Four Dimensions
int dy[] = {0, 0, 1, -1};

bool valid(int x, int y) {                //All the conditions required to visit this node
    return (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != '#' && dis[x][y] == OO);
}

void BFS(int ratx, int raty) {
    memset(dis, OO, sizeof dis);
    queue<pair<int, int> > q;
    q.push({ratx, raty});
    dis[ratx][raty] = 0;
    while (!q.empty()) {
        int parentx = q.front().first, parenty = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int childx = parentx + dx[i], childy = parenty + dy[i];
            if (!valid(childx, childy)) continue;
            dis[childx][childy] = dis[parentx][parenty] + 1;
            q.push({childx, childy});
        }
    }
}


void DFS(int p) {
    vis[p] = 1;
    for (int ch: adj[p])
        if (!vis[ch]) DFS(ch);
}

void countNofComps() { // on undirected graph
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) DFS(i), ++num;
    }
    printf("number of components = %d\n", num);
}

void floodFill() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> grid[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'R') rx = i, ry = j;
            else if (grid[i][j] == 'C') cx = i, cy = j;
        }
    }
    BFS(rx, ry);
    if (dis[cx][cy] == OO)
        puts("The Cheese isn't reachable");
    else
        printf("The shortest Path from Rat to Cheese is %d steps.\n", dis[cx][cy]);


}

int main() {
    FastIO()
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif

//    countNofComps()
//    floodFill()

    return 0;
}
