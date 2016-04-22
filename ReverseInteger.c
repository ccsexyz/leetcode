// https://leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        if(x == 0 || x == INT_MIN)
            return 0;
        int flag = x < 0;
        if(flag) x = -x;
        vector<int> nums;
        while(x) {
            nums.push_back(x % 10);
            x /= 10;
        }
        int ret = 0;
        for(auto &x : nums) {
            if(ret > INT_MAX / 10) {
                return 0;
            }
            ret *= 10;
            ret += x;
        }
        if(flag)
            return -ret;
        else
            return ret;
    }
};
