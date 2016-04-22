// https://leetcode.com/problems/single-number/

class Solution {
public:
    int reverse(int x) {
        return std::accumulate(nums.begin(), nums.end(), 0, [](int a, int b) { return a ^ b; });
    }
};
