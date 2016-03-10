// https://leetcode.com/problems/maximum-gap/

#define Max(a, b) (a > b ? a : b)
#define Min(a, b) (a < b ? a : b)
int maximumGap(int *nums, int numsSize) {
    if (numsSize < 2)
        return 0;
    int ret = 0;
    int maxv = INT_MIN;
    int minv = INT_MAX;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > maxv)
            maxv = nums[i];
        if (nums[i] < minv)
            minv = nums[i];
    }
    double gap = ((double)(maxv - minv)) / numsSize;
    int maxV[numsSize - 1];
    int minV[numsSize - 1];
    for (int i = 0; i < numsSize - 1; i++) {
        maxV[i] = INT_MIN;
        minV[i] = INT_MAX;
    }
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == maxv)
            continue;
        int bkid = (int)((nums[i] - minv) / gap);
        maxV[bkid] = Max(nums[i], maxV[bkid]);
        minV[bkid] = Min(nums[i], minV[bkid]);
    }
    int curr_max_gap = maxV[0];
    for (int i = 1; i < numsSize - 1; i++) {
        if (minV[i] != INT_MAX) {
            ret = Max(minV[i] - curr_max_gap, ret);
            curr_max_gap = maxV[i];
        }
    }
    ret = Max(ret, maxv - curr_max_gap);
    return ret;
}
