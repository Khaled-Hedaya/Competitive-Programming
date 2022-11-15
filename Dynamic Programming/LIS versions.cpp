#include <bits/stdc++.h>
 
using namespace std; 
#define ll long long

const int OO = 0x3f3f3f3f;

// solution 1: longest increasing subseq
// we define d[i] = the length of the longest increasing subs that ends in the element at index i
// so we have d[i] = 1 or d[i] > 1
// d[i] = 1 when current element is the first one in the sequence
// d[i] > 1 when we add the length of the best d[j] to the current element at index i, where d[j] is the maximum, so d[i] = d[j] + 1

int lis1(vector < int > &v){
	int n = (int)v.size();
	vector < int > dp(n, 1);
	for(int i = 0 ; i < n; ++i){
		for(int j = 0; j < i; ++j){
			if(v[j] < v[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	int ans = dp[0];
	for(int i = 1; i < n; ++i)
		ans = max(ans, dp[i]);
	return ans;
}
// restoring the subseq itself from sol1:
// we define p[i] = the index j of the second last element in the longest inc subs ending at index i
// Then to derive the subsequence, we just start at the index i with the maximal d[i], and follow the ancestors until we deduced the entire subsequence, i.e. until we reach the element with d[i] = 1

vector < int > res_seq1(vector < int > &v){
	int n = (int)v.size();
	vector < int > dp(n, 1), prev(n, -1);
	// intially all elements have no previous elements (prev[i] = -1)
	for(int i = 0 ; i < n; ++i){
		for(int j = 0 ; j < i; ++j){
			if(v[j] < v[i] && dp[i] < dp[j] + 1){
				dp[i] = dp[j] + 1;
				prev[i] = j;
			}
		}
	}
	int ans = dp[0], idx = 0;
	for(int i = 1; i < n; ++i){
		if(dp[i] > ans){
			ans = dp[i];
			idx = i;
		}
	}
	vector < int > ret;
	while(idx != -1){
		ret.push_back(v[idx]);
		idx = prev[idx];
	}
	reverse(ret.begin(), ret.end());

	return ret;
}

// -----  ###################################  ----
// in this solution dp[i] = the smallest element at which a subseq of length i terminates
// the LIS is the max 'l' such dp[l] < OO and 1 <= l <= n
int lis2(vector < int > &v){
	int n = (int)v.size();
	vector < int > dp(n + 1, OO);
	dp[0] = -OO;
	for(int i = 0; i < n; ++i){
		int len = upper_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
		if(dp[len - 1] < v[i] && v[i] < dp[len])
			dp[len] = v[i];
	}
	int mxLen = 0;
	for(int l = 0 ; l <= n; ++l){
		if(dp[l] < OO)
			mxLen = l;
	}
	return mxLen;

}

// ###########################################
// find count number of longest increasing subs

int count_LIS(vector < int > &v){
	int n = (int)v.size();
	vector < int > dp(n, 1), dp_c(n, 1);
	for(int i = 0 ; i < n; ++i){
		for(int j = 0; j < i; ++j){
			if(v[j] < v[i]){
				if(dp[j] + 1 > dp[i]){
					dp[i] = dp[j] + 1;
					dp_c[i] = dp_c[j];
				}
				else if(dp[j] + 1 == dp[i])
					dp_c[i] += dp_c[j];
			}
		}
	}
	int mxLen = dp[0];
	for(int i = 1; i < n; ++i)
		mxLen = max(mxLen, dp[i]);
	int cnt = 0; // stores the count of LIS with mxLen
	for(int i = 0 ; i < n; ++i){
		if(dp[i] == mxLen)
			cnt += dp_c[i];
	}
	return cnt;

}



int main(){

	#ifdef ONPC
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);

	#endif

	int n;
	cin >> n;
	vector < int > a;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		a.push_back(x);
	}
	cout << lis1(a) << "\n";
	auto ans = res_seq1(a);
	for(auto e : ans)
		cout << e << " ";
	cout << "\n";
	cout << lis2(a) << "\n";

	cout << count_LIS(a) << "\n";

	return 0;
}
