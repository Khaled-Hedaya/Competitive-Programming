#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, OO = 0x3f3f3f3f;


vector<pair<int, int>> primeFactorization(int n) {
    vector<pair<int, int> > factors;
    for (int i = 2; i * i <= n; ++i) {
        int power = 0;
        while (n % i == 0) {
            n /= i;
            ++power;
        }
        if (power) factors.push_back({i, power});
    }

    if (n > 1) factors.push_back({n, 1});
    return factors;
}

int main() {

    int x = 36;
    auto items = primeFactorization(x);
    int sz = (int)items.size();
    for(int i = 0 ; i < sz ; ++i) {
        cout << items[i].first << "^" << items[i].second;
        if(i != sz-1)
            cout << " * ";
    }
    cout << "\n";



    return 0;
}




