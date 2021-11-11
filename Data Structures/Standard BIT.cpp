#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
const int N = 1e5 + 10, OO = 0x3f3f3f3f;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

struct BIT {
    vector<ll> nodes;
    int sz;

    explicit BIT(int n) {
        nodes.resize(n + 1);
        sz = n;
    }
    // [[ works in ZERO based ]]
    ll get(int i) { // sum of range [0 , i]
        ll sum = 0;
        for (++i; i; i -= i & -i) sum += nodes[i];
        return sum;
    }

    void update(int i, ll x) { // recieve idx to update its value by "x"
        for (++i; i <= sz; i += i & -i)
            nodes[i] += x;
    }

    ll query(int l, int r) { // get pref[r] - pref[l-1]
        return get(r) - get(l - 1);
    }

};

int main() {
    FastIO()
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif


    return 0;
}
