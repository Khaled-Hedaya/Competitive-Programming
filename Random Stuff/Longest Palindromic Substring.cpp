#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
const int N = 1e5 + 10, OO = 0x3f3f3f3f;

/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/

int dp[100][100];
string s;

// this function finds the longest (in length) palindromic -Substring-
int isPalind(int l, int r) {
    if (l > r)
        return 0;
    if (l == r)
        return 1;
    int &ret = dp[l][r];
    if (~ret) return ret;
    if (s[l] == s[r]) {
        int len = r - l - 1;
        if (len == isPalind(l + 1, r - 1)) // MUST DO this condition!.. bec, we want it as a substring not subsequence
            return ret = 2 + len;
    }
    return ret = max(isPalind(l + 1, r), isPalind(l, r - 1));
}

string path; // to store the answer (maximum palindromic substring)

//so bad build function but works! :) I think maybe later I will update it and write more good one!
void build(int l,int r) { 
    if (l > r)
        return;
    if (l == r) {
        path[l] = s[l];
        return;
    }
    int &ret = dp[l][r];
    if (s[l] == s[r]) {
        int len = r - l - 1;
        if (len == isPalind(l + 1, r - 1)) {
            path[l] = s[l];
            path[r] = s[r];
            build(l + 1, r - 1);
            return;
        }
    }
    if (ret == isPalind(l + 1, r)) {
        path[l] = '$';
        build(l + 1, r);
        return;
    }
    path[r] = '$';
    build(l, r - 1);
}


int main() {
    FastIO()
#ifdef ONPC
    freopen("in.txt", "r", stdin);
#endif
    memset(dp, -1, sizeof dp);
    s = "aacabdkacaa";
    int sz = (int) s.size();
    path.resize(sz);
    fill(path.begin(), path.end(), '$');
    int ans = isPalind(0, sz - 1);
    cout << "mx length = " << ans << "\n";
    build(0, sz - 1);
    cout << path << "\n"; // the substring with none '$' is the answer!
    return 0;
}
