
// Problem Link: https://leetcode.com/problems/fraction-to-recurring-decimal/

class Solution {
public:
    #define ll long long
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0)
            return "0";
        bool isPos = 0;
        if((numerator > 0 && denominator > 0) or (numerator < 0 && denominator < 0))
            isPos = 1;
        ll n = abs(numerator);
        ll d = abs(denominator);
        string ret = "";
        unordered_map < ll , int > mp; // rem -> position
        if(n >= d){
            ret += to_string(n / d);
            n %= d;
        }
        else{
            ret += "0";
        }
        if(n == 0){
            if (!isPos)
                ret = "-" + ret;
            return ret;
        }
        else{
            ret += ".";
            mp[n] = (int)ret.size();
        }
        
        while(n > 0){
            n *= 10;
            if(n >= d){
                ret += to_string(n / d);
                n %= d;
            }
            else{
                ret += "0";
            }
            if(mp.count(n)){ // the remainder starts to repeat!
                ret.insert(mp[n] , "(");
                ret += ')';
                break;
            }
            mp[n] = (int)ret.size();
        }
        cout << isPos << "\n";
        if(!isPos)
            ret = "-" + ret;
        return ret;
    }
};
