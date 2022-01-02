// problem link: https://leetcode.com/problems/kth-largest-element-in-an-array/
// quick select: worst case -> O(n^2) .. average case -> O(n)

class Solution {
public:
    int target;
    int quick_select(int l , int r , vector<int> &a){
        int pivot = a[r], p_idx = l;
        for(int i = l ; i < r; ++i){
            if(a[i] <= pivot){
                swap(a[i] , a[p_idx]);
                p_idx++;
            }
        }
        swap(a[p_idx], a[r]);
        if(p_idx == target) return a[target];
        if(p_idx < target)
            return quick_select(p_idx + 1, r, a);
        else return quick_select(l , p_idx - 1, a);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = (int)nums.size();
        target = n - k;
        return quick_select(0, n - 1, nums);
    }
};
