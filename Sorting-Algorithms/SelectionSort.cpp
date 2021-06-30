#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, OO = 0x3f3f3f3f;


void selection_sort(int a[], int sz) {

    for (int i = 0; i < sz - 1; ++i) {
        int mn_idx = i;
        for (int j = i + 1; j < sz; ++j) {
            if (a[j] < a[mn_idx])
                mn_idx = j;
        }
        int tmp = a[i];
        a[i] = a[mn_idx];
        a[mn_idx] = tmp;
    }

}


int main() {

    int arr[] = {4, 8, 1, 12, 3, 6};

    selection_sort(arr, 6);

    for (int i = 0; i < 6; ++i)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}




