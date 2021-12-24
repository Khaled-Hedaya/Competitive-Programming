
// problem link: https://leetcode.com/problems/longest-consecutive-sequence/
// idea: every consecutive sequece has a start element, which has no previous element
// (1 2 3 4 5 6)----- (100 101) ---------- (205 206 207)


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = (int)nums.size();
        if(n == 0)
            return 0;
        int curLen = 1;
        int mxLen = 1;
        unordered_set < int > st;
        for(int i = 0 ; i < n;  ++i){
            st.insert(nums[i]);
        }
        
        for(int i = 0 ; i < n ; ++i){
            if(st.count(nums[i] - 1))
                continue;
            // this element is a start for some sequence
            curLen = 1;
            int v = nums[i];
            while(st.count(++v))
                curLen++;
            mxLen = max(mxLen, curLen);
        }
        return mxLen;
    }
};
