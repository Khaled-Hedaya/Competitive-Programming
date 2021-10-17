#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
const int N = 1e5 + 10, OO = 0x3f3f3f3f;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

int n, mat[200][200], nxt[200][200];

void floyd() {
    for (int k = 0; k < n; ++k)
        for (int a = 0; a < n; ++a)
            for (int b = 0; b < n; ++b) {
                if (mat[a][k] >= OO || mat[k][b] >= OO)
                    continue;
                int newDist = mat[a][k] + mat[k][b];
                if (newDist < mat[a][b]) {
                    mat[a][b] = max(newDist, -OO);
                    nxt[a][b] = k;
                }
            }
}

void printPathUtli(int a, int b) {
    if (nxt[a][b] == -1) return;
    int mid = nxt[a][b];
    printPathUtli(a, mid);
    cout << mid << " ";
    printPathUtli(mid, b);
}

void printPath(int src, int dest) {
    cout << src << " ";
    printPathUtli(src, dest);
    cout << dest << "\n";
}


int main() {
    FastIO()
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif

    memset(mat, OO, sizeof mat);
    memset(nxt, -1, sizeof nxt);
    
    //read graph input
    
    // run floyd()!
    

    return 0;
}
