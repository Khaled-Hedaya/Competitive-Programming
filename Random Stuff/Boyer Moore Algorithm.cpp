// problem: https://leetcode.com/problems/majority-element/description/

class Solution {
public:
    // boyer moore Algo for finding the majority element that has frequency greater than floor(n/2) where n is the size of array
    int majorityElement(vector<int>& nums) {
        int cnt = 1, ans = nums[0];
        int n = (int)nums.size();
        for(int i = 1 ; i < n; ++i){
            if(cnt == 0)
                ans = nums[i];
            cnt += (nums[i] == ans ? 1 : -1);
        }
        return ans;
    }
};
