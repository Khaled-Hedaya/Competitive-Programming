#include "bits/stdc++.h"
using namespace std;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define FastIO() ios::sync_with_stdio(false), cin.tie(0)

const int N = 1e5 + 10, OO = 0x3f3f3f3f;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

int minFactor[N];

// we want to update sieve to answer :
// given a number(X), factorize it to its prime factors -- Faster than trivial
// factorization

void modifiedSieve() {
  iota(minFactor, minFactor + N, 0);
  minFactor[0] = minFactor[1] = -1; // invalid date
  for (int i = 2; i <= N / i; i += 1 + (i & 1)) {
    if (minFactor[i] == i) { // its prime
      for (int j = i * i; j < N; j += i)
        if (minFactor[j] == j)
          minFactor[j] = i;
    }
  }
}

vector<int> factorize(int x) { // O(log x)
  vector<int> ret;
  while (x > 1) {
    ret.push_back(minFactor[x]);
    x /= minFactor[x];
  }
  return ret;
}

int main() {

  FastIO();

  modifiedSieve();
  // for (int i = 0; i <= 30; ++i) {
  //   cout << i << ": ";
  //   cout << minFactor[i] << "\n";
  // }
  int n = 24;
  vector<int> ans = factorize(n);
  for (auto e : ans)
    cout << e << " ";
  cout << "\n";

  return 0;
}
