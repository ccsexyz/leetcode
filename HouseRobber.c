// https://leetcode.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int> &nums) {
        int first = 0, second = 0, third = 0, most = 0;

        for (int i = 0; i < nums.size(); ++i) {
            int local = max(first, second) + nums[i];
            most = max(most, local);
            first = second;
            second = third;
            third = local;
        }
        return most;
    }
};
