#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
const int N = 1e5 + 10, OO = 0x3f3f3f3f;

// finding the lognest increasing or non-decreasing subsequence in O(n*logn) time

int a[N]; // array of numbers given in input
int n; // number of elements in input

// finding the longest increasing (without duplicate) subsequence length

//style 1:
int LIS1() {
	set < int > st;
	for (int i = 0; i < n; ++i) {
		st.insert(a[i]);
		auto it = st.upper_bound(a[i]);
		if (it != st.end())
			st.erase(it);
	}
	return (int)st.size();
}
// style 2:
int LIS2() {
	multiset < int > st;
	for (int i = 0 ; i < n ; ++i) {
		st.insert(a[i]);
		auto it = st.lower_bound(a[i]);
		it++;
		if (it != st.end())
			st.erase(it);
	}
	return (int)st.size();
}

// finding the longest nondecreasing (with duplicates) subsequence length
int LNDS() {
	multiset < int > st;
	for (int i = 0 ; i < n ; ++i) {
		st.insert(a[i]);
		auto it = st.upper_bound(a[i]);
		if (it != st.end())
			st.erase(it);
	}
	return (int)st.size();
}


int main() {
	FastIO()
#ifdef ONPC
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	cin >> n;
	for (int i = 0 ; i < n ; ++i)
		cin >> a[i];

	cout << LIS1() << " should be = to " << LIS2() << "\n";
	cout << LNDS() << "\n";

	return 0;
}
