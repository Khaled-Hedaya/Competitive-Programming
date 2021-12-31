// problem link: https://codeforces.com/contest/920/problem/E


#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
const int N = 200000 + 10, OO = 0x3f3f3f3f;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

int n , m;
set < pair<int, int> > removed;
set < int > unVis;


int main() {
	FastIO()
#ifdef ONPC
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> m;
	for (int i = 0 ; i < m ; ++i) {
		int a , b;
		cin >> a >> b;
		removed.insert({a , b});
		removed.insert({b , a});
	}
	for (int i = 1 ; i <= n ; ++i)
		unVis.insert(i);

	vector < int > comp;
	while (!unVis.empty()) {
		int sz = 0; // size of each component
		queue < int > q;
		q.push(*unVis.begin());
		unVis.erase(unVis.begin());

		while (!q.empty()) {
			++sz;
			int cur = q.front();
			q.pop();
			for (auto it = unVis.begin() ; it != unVis.end();) {
				int nxt = *it;
				if (removed.find(make_pair(cur , nxt)) == removed.end()) { //there is an edge between cur & nxt
					q.push(nxt);
					//auto tmp = it;
					//it++;
					it = unVis.erase(it);
				}
				else { // skip it, there is no edge between cur & nxt
					++it;
				}
			}
		}
		comp.push_back(sz);
	}
	sort(comp.begin(), comp.end());
	cout << comp.size() << "\n";
	for (auto x : comp)
		cout << x << " " ;
	cout << "\n";

	return 0;
}
