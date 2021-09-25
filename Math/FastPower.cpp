#include "bits/stdc++.h"
using namespace std;

#define FastIO() ios::sync_with_stdio(false), cin.tie(0)
const int N = 1e5 + 10, OO = 0x3f3f3f3f;
#define ll long long

// 2^13 = 2 * [(4)^6] = 2 * [(16)^3] = 2 * 16 * [256^1] = 2 *16 * 256 * [x^0]

// we can pass mod (m) as a parameter in this function
ll fastPow(ll base, ll power /*, ll m*/) { // O(log[power])
  ll ans = 1;
  while (power) {
    if (power & 1)
      ans = (ans * base); // if we have mod => ans = (ans * base) % m
    base = (base * base); // base = (base * base) % m
    power >>= 1;
  }
  return ans;
}

int main() {

  FastIO();
  for (int i = 0; i < 10; ++i) {
    int x, y;
    cin >> x >> y;
    cout << fastPow(x, y) << "\n";
    cout.flush();
  }

  return 0;
}
