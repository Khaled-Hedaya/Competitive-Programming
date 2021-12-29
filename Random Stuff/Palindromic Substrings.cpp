// problem link: https://leetcode.com/problems/palindromic-substrings/

// idea: consider every position in the string as a middle element
// of a palindrome, and start to expand one letter left & right

class Solution {
public:
    int countSubstrings(string s) {
        int n = (int)s.size();
        int l , r, ans = 0;
        for(int i = 0 ; i < n ; ++i){ // check odd palindromes of lengths (1, 3, 5, ...)
            l = r = i;
            int cnt = 0;
            while(l >= 0 && r < n && s[l] == s[r]){
                cnt++;
                --l, r++;
            }
            ans += cnt;
        }
        // check even palindromes of lengths (2, 4, 6, ...)
        for(int i = 1 ; i < n ; ++i){
            l = i - 1 , r = i;
            int cnt = 0;
            while(l >= 0 && r < n && s[l] == s[r]){
                cnt++;
                --l, r++;
            }
            ans += cnt;
        }
        
        return ans;
    }
};
