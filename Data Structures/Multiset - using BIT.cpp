#include <bits/stdc++.h>

#define endl '\n'
const int N = 200001;
using namespace std;
typedef long long ll;

struct BIT {
    vector<int> v;
    int sz;

    explicit BIT(int n) {
        v.resize(n);
        sz = n;
    }

    //gets sum of range [0, i]
    int get(int i) {
        ll ret = 0;
        for (++i; i; i -= i & -i)
            ret += v[i - 1];
        return ret;
    }

    void update(int i, int x) {
        for (++i; i <= sz; i += i & -i)
            v[i - 1] += x;
    }

    int query(int st, int en) {
        return get(en) - get(st - 1);
    }
};

//MULTI-SET
struct Multiset {
    BIT bit;

    Multiset(int max) : bit(max + 1) {}

    void insert(int v) {
        bit.update(v, 1);
    }

    void erase(int v) {
        if (count(v))
            bit.update(v, -1);
    }

    int count(int v) {
        return bit.query(v, v);
    }

    int countSmaller(int v) {
        return bit.get(v - 1);
    }
};

int arr[N];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef CLION
    freopen("in", "rt", stdin);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", arr + i);
            mx = max(mx, arr[i]);
        }
        Multiset s(mx);
        ll ans = 0;
        for (int i = n - 1; ~i; --i) {
            s.insert(arr[i]);
            ans += s.countSmaller(arr[i]);
        }
        printf("%lld\n", ans);
    }
}
