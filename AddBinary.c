// https://leetcode.com/problems/add-binary/

class Solution {
public:
    string addBinary(string a, string b) {
        string ret;

        int l1 = a.length();
        int l2 = b.length();

        int carry = 0;
        while(l1 > 0 || l2 > 0) {
            l1--;
            l2--;
            if(l1 >= 0) {
                carry += a[l1] - '0';
            }
            if(l2 >= 0) {
                carry += b[l2] - '0';
            }

            if(carry % 2 == 0) {
                ret = '0' + ret;
            } else {
                ret = '1' + ret;
            }
            if(carry >= 2) {
                carry = 1;
            } else {
                carry = 0;
            }
        }

        if(carry == 1) {
            ret = '1' + ret;
        }

        return ret;
    }
};
