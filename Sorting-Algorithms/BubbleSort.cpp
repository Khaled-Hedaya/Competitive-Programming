#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, OO = 0x3f3f3f3f;

void bubble_sort(int a[], int sz) {
    for (int pass = 0; pass < sz - 1; pass++) {
        bool f = 0;
        for (int i = 0; i < sz - pass - 1; ++i) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                f = 1;
            }
        }
        if (!f) break;
    }
}


int main() {

    int arr[] = {4, 8, 1, 12, 3, 6};

    bubble_sort(arr, 6);

    for (int i = 0; i < 6; ++i)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}




