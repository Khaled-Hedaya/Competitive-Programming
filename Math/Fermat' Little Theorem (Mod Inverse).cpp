#include <bits/stdc++.h>

using namespace std;
#define FastIO() ios::sync_with_stdio(false), cin.tie(0)
#define ll long long

const int N = 1e5 + 10, OO = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

ll power(ll x, ll p) {
    ll ans = 1;
    while (p) {
        if (p & 1)
            ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        p >>= 1;
    }
    return ans;
}
// fermat's little theorem
ll inv(ll x) {
    return power(x, MOD - 2);
}

void solve() {
    // we want to calculate for ex: (12 / 2) mod 1e9 + 7
    // a/b mod m = (a * b^-1) mod m = (a % m * b^-1 % m) % m
    ll a, b;
    cin >> a >> b;
    cout << ((a % MOD) * (inv(b) % MOD)) % MOD << "\n";
}


int main() {

    FastIO();

    solve();

    return 0;
}
