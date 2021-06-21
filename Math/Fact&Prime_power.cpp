#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, OO = 0x3f3f3f3f;
#define ll long long

// Given a (prime p) and (n!), what is the max (x) such that n! is divisible by p^x ?

ll sol1(ll n, ll p) {    // O(!n / p)
    ll fact = 1;
    while (n)
        fact *= n, --n;

    int cnt = 0;
    while (fact % p == 0)
        fact /= p, cnt++;

    return cnt;
}
///////////////////////////////

int sol2(int n, int p){ //O(log(n) base p) -- definetly better
    int mx_pow = 0;
    for(int i = p; i <= n ; i *= p)
        mx_pow += (n / i);
    return mx_pow;
}

int main() {

    int n = 16 , p = 3; // p --> must be a prime number
    cout << sol1(n , p) << "\n";
    cout << sol2(n , p) << "\n";


    return 0;
}




