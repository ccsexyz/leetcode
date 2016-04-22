// https://leetcode.com/submissions/detail/59696103/

int integerBreakHelper(int n, int *nums) {
    if(n == 2 || n == 1)
        return 1;
    if(nums[n] != 0)
        return nums[n];
    int max = 0;
    for(int i = n - 1; i > 0; i--) {
        int ret = integerBreakHelper(n - i, nums);
        if(ret > n - i) {
            ret *= i;
        } else {
            ret = i * (n - i);
        }
        if(ret > max) {
            max = ret;
        }
    }
    nums[n] = max;
    return max;
}

int integerBreak(int n) {
    if(n <= 0)
        return 0;

    int *solv = malloc(sizeof(int) * (n + 1));
    memset(solv, 0, sizeof(int) * (n + 1));

    return integerBreakHelper(n, solv);
}
