
// problem link: https://cses.fi/problemset/task/1682/
// idea :
/*  
The theorem used here is that if one vertex can both reach and be reached by
all others, then every vertex in this graph can reach all others.

Let's say can[u][v] is true if you can go from vertex (u) to vertex
(v) through a series of edges. Additionally, let's define the directed graph
given in the statement as G and the reverse of it (where an edge
u -> v becomes v -> u) as G'. Then, if can[1][x] for 1 <= x <= n in both G and G', the answer is "YES".

To compute can[1][x], we can run a dfs from from vertex 1 and check
if you can reach vertex x for all 1 <= x <= n. If we can't, then print (1, x) if you're running the DFS on G 
and (x, 1) otherwise.

*/


#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
const int N = 1e5 + 10, OO = 0x3f3f3f3f;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

int n, m;
vector < int > adj[N][2];
int vis[N], vid;
void dfs(int src, int type) {
	vis[src] = vid;
	for (auto ch : adj[src][type]) {
		if (vis[ch] != vid)
			dfs(ch, type);
	}
}

int main() {
	FastIO()
#ifdef ONPC
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> m;
	for (int i = 0 ; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a , --b;
		adj[a][0].push_back(b); // orignal edges
		adj[b][1].push_back(a); // reversed edges
	}
	++vid;
	dfs(0, 0);
	for (int i = 0 ; i < n ; ++i) {
		if (vis[i] != vid) {
			cout << "NO\n";
			cout << 1 << " " << i + 1 << "\n";
			return 0;
		}
	}
	//cout << "#################\n";
	++vid;
	dfs(0, 1);
	for (int i = 0 ; i < n; ++i) {
		if (vis[i] != vid) {
			cout << "NO\n";
			cout << i + 1 << " " << 1 << "\n";
			return 0;
		}
	}
	cout << "YES\n";


	return 0;
}
