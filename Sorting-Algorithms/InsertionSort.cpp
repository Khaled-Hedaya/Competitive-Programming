#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, OO = 0x3f3f3f3f;

void insertion_sort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int val = a[i];
        int j = i;
        while (j > 0 && val < a[j - 1]) {
            a[j] = a[j - 1];
            j = j - 1;
        }
        a[j] = val;
    }
}


int main() {

    int arr[] = {4, 8, 1, 12, 3, 6};

    insertion_sort(arr, 6);

    for (int i = 0; i < 6; ++i)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}




