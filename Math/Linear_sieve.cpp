#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10, OO = 0x3f3f3f3f;


bitset<N> isPrime;

void linear_sieve() {
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    vector<int> primes;
    for (ll i = 2; i <= N; ++i) {
        if (isPrime[i])
            primes.push_back(i);
        int sz = primes.size();
        for (int j = 0; j < sz && i * primes[j] <= N; ++j) {
            isPrime[i * primes[j]] = 0;
            if (i % primes[j] == 0) break;
        }

    }
}

int main() {
    FastIO()

    linear_sieve();
    if (isPrime[11]) cout << "11 is prime\n";
    else cout << "11 is not prime\n";


    return 0;
}




