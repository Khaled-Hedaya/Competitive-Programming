#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10, OO = 0x3f3f3f3f;


bitset<N> isPrime;
vector<int> primes;

void sieve() { // O(n loglogn)
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= N; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i)
                isPrime[j] = 0;
        }
    }
    for (int i = 2; i <= N; ++i)
        if (isPrime[i])
            primes.emplace_back(i);
}

int main() {

    sieve();
    int sz = (int) primes.size();
    for (int i = 0; i < sz; ++i)
        printf("%d\n", primes[i]);


    return 0;
}




