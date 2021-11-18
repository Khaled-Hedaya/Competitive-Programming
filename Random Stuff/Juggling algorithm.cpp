// Juggling algorithm for array rotation 
// problem link: https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/646/

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
const int N = 2e5 + 10, OO = 0x3f3f3f3f;
/*
"Maybe they aren't stars.. Maybe they are a map to get out of here"
*/


class Solution {
public:
	// rotate array to the left or right (k) times, in O(1) extra space
	
	int gcd(int a , int b){
		if(b == 0)
			return a;
		return gcd(b , a % b);
	}
	
    void rotateLeft(vector<int>& nums, int k) {
		int n = (int)nums.size();
		int GCD = gcd(n , k);
		for(int curSetIdx = 0 ; curSetIdx < GCD ; ++curSetIdx){
			int temp = nums[curSetIdx];
			int j = curSetIdx;
			while(1){
				int d = (j + k) % n;
				if(d == curSetIdx)
					break;
				nums[j] = nums[d];
				j = d;
			}
			nums[j] = temp;
		}
    }
    
    void rotateRight(vector<int>& nums, int k) {
		int n = (int)nums.size();
		int GCD = gcd(n , k);
		
		
		for(int curSetIdx = GCD - 1 ; curSetIdx >= 0 ; --curSetIdx){
			int temp = nums[curSetIdx];
			int j = curSetIdx;
			while(1){
				int d = (((j - k) % n) + n) % n;
				if(d == curSetIdx)
					break;
				nums[j] = nums[d];
				j = d;
			}
			nums[j] = temp;
		}
    }
    
    void print(vector<int> &nums){
		int n = (int)nums.size();
		for(int i = 0 ; i < n ; ++i){
			printf("%d ", nums[i]);
		}
		puts("");
	}
};

int main() {
//    FastIO()
	
	
	Solution sol;
	int n, m;
	scanf("%d %d" , &n, &m);
	vector<int> v(n);
	for(auto &x : v)
		scanf("%d" , &x);
	
	sol.rotateRight(v , m);
	sol.print(v);
	

    return 0;
}
