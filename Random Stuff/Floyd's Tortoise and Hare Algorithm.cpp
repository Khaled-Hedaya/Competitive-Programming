
// problem link: https://leetcode.com/problems/find-the-duplicate-number/
// proved mathematically! --> https://www.youtube.com/watch?v=PvrxZaH_eZ4

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
        
    }
};
