#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, OO = 0x3f3f3f3f;

void merge(int A[], int start, int mid, int end) {
    //stores the starting position of both parts in temporary variables.
    int p = start, q = mid + 1;
    int tmp[end - start + 1], k = 0;

    for (int i = start; i <= end; i++) {
        if (p > mid)      //checks if first part comes to an end or not .
            tmp[k++] = A[q++];
        else if (q > end)   //checks if second part comes to an end or not
            tmp[k++] = A[p++];
        else if (A[p] < A[q])     //checks which part has smaller element.
            tmp[k++] = A[p++];
        else
            tmp[k++] = A[q++];
    }
    for (int p = 0; p < k; p++)
        A[start++] = tmp[p];
}

void merge_sort(int A[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(A, start, mid);
        merge_sort(A, mid + 1, end);

        merge(A, start, mid, end);
    }
}

int main() {

    int arr[] = {4, 8, 1, 12, 3, 6};

    merge_sort(arr, 0, 5);

    for (int i = 0; i < 6; ++i)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}




