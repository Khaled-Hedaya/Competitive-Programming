// problem link: https://leetcode.com/problems/sum-of-two-integers/


class Solution {
public:
    
    
    int getSum(int a, int b) {
        while(b != 0){
            int carry = (unsigned)(a & b) << 1; // must cast to unsigned, case : (a = -1, b = 1) we need to iterate on int bits + 1 outside
            a = a ^ b; // new sum
            b = carry; 
        }
        return a;
    }
    
};
