#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, OO = 0x3f3f3f3f;


ll extended_gcd(ll a, ll b, ll &x, ll &y) { //gcd(a, b) = [a*x] + [b*y]
                                          // new_x = prev_y , new_y = prev_x - [(a / b) * new_x]
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll g = extended_gcd(b, a % b, y, x);
    y = y - ((a / b) * x);
    return g;
}


int main() {

    ll x, y, GCD;
    GCD = extended_gcd(1180, 482, x, y);
    cout << GCD << " " << x << " " << y << "\n";


    return 0;
}




