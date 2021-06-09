#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, OO = 0x3f3f3f3f;

bool isPrime(int n) { // O(sqrt(n))
    if (n == 2) return true;
    if (n < 2 || !(n & 1)) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}


int main() {
    
    int x;
    cin >> x;
    if (isPrime(x)) cout << x << " is prime number\n";
    else cout << "Not prime\n";


    return 0;
}




