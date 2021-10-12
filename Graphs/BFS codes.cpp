#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
const int N = 1e3 + 10, OO = 0x3f3f3f3f;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

int n, m, a, b, x;
vector<int> adj[N];
int dis[N];

void BFS(int src) {
    memset(dis, OO, sizeof dis);
    queue<int> q;
    q.push(src);
    dis[src] = 0;
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        for (int ch: adj[p])
            if (dis[ch] == OO) {
                dis[ch] = dis[p] + 1;
                q.push(ch);
            }
    }
}

int main() {
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    scanf("%d", &x);
    memset(dis, OO, sizeof dis);
    BFS(x);
    for (int i = 1; i <= n; ++i)
        printf("The Shortest Path between %d and %d is %d\n", x, i, dis[i]);

    return 0;
}
