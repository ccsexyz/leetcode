// https://leetcode.com/submissions/detail/59719723/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int i = 0;
        for(auto &x : nums) {
            auto it = m.find(x);
            if(it != m.end())
                return vector<int>{i, it->second};
            m[target - x] = i++;
        }
        return vector<int>{0, 0};
    }
};
