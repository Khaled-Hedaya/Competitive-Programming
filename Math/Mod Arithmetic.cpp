#include <bits/stdc++.h>

using namespace std;

const int m = 1e9 + 7;


int sum(int a, int b) {
    a = (a % m + m) % m;
    b = (b % m + m) % m;
    return (a + b) % m;
}

int mul(int a, int b) {
    a = (a % m + m) % m;
    b = (b % m + m) % m;
    return (a * 1LL * b) % m;
}

int power(int x, int y) {
    if (y == 0) return 1;
    int temp = power(x, y / 2);
    if (y % 2 == 0) return mul(temp, temp);
    return mul(mul(x, temp), temp);
}

int modInverse(int x) {
    return power(x, m - 2);
}

const int N = 1e6 + 5;
int fact[N];

int nCr(int n, int r) {
    return mul(fact[n], modInverse(mul(fact[r], fact[n - r])));

}

int a, b, n;

bool check(int x) {
    while (x) {
        int temp = x % 10;
        if (temp != a && temp != b) return false;
        x /= 10;
    }
    return true;
}

int main() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);
    cin >> a >> b >> n;
    int ans = 0;
    for (int num_of_as = 0; num_of_as <= n; num_of_as++) {
        int num_of_bs = n - num_of_as;
        if (check(a * num_of_as + b * num_of_bs))
            ans = sum(ans, nCr(n, num_of_as));
    }
    cout << ans;
//    cout << __gcd(16, 36) << "\n";
//    auto v = getPrimeFactors(22);
//    for (auto it : v) cout << it << ' ';
}
