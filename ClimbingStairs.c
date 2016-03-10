// https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> solutions(n + 1, -1);
        solutions[1] = 1;
        solutions[2] = 2;
        function<int(int)> f;
        f = [&](int s) -> int {
            if (solutions[s] != -1)
                return solutions[s];
            return solutions[s] = f(s - 1) + f(s - 2);
        };
        return f(n);
    }
};
