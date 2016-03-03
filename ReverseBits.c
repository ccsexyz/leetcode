// https://leetcode.com/problems/reverse-bits/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        static uint32_t *nums = [](){
            static uint32_t nums[32];
            for(int i = 0; i < 32; i++) {
                nums[i] = 1 << (31 - i);
            }
            return &(nums[0]);
        }();

        uint32_t ret = 0;
        for(int i = 0; i < 32; i++) {
            if(n & nums[i]) {
                ret += 1 << (i);
            }
        }

        return ret;
    }
};
