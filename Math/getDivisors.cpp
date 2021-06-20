#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, OO = 0x3f3f3f3f;


vector<int> get_divisors(int n) { // O(sqrt n)
    vector<int> div;
    int i;
    for (i = 1; i * i < n; ++i) {
        if (n % i == 0) {
            div.push_back(i);
            div.push_back(n / i);
        }
    }
    if (i * i == n)
        div.push_back(i);
    return div;
}

int main() {

    int x = 16;
    auto items = get_divisors(x);
    for(auto e : items)
        cout << e << " ";
    cout << "\n";


    return 0;
}




