// https://leetcode.com/problems/plus-one/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ret;
        ret.reserve(digits.size() + 1);
        int carry = 1;
        for(int i = digits.size() - 1; i >= 0; i--) {
            carry += digits[i];
            if(carry >= 10) {
                ret.push_back(carry % 10);
                carry = 1;
            } else {
                ret.push_back(carry);
                carry = 0;
            }
        }
        if(carry == 1) {
            ret.push_back(1);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
