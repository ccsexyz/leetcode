// https://leetcode.com/problems/find-the-duplicate-number/

int findDuplicate(int* nums, int numsSize) {
    int flags[65536];
    int groups = numsSize / 65536 + numsSize % 65536 == 0 ? 0 : 1;
    for(int i = 0; i < groups; i++) {
        int base = i * 65536;
        memset(flags, 0, sizeof(int) * 65536);
        for(int j = 0; j < numsSize; j++) {
            int tmp = nums[j] - base;
            if(tmp >= 0 && tmp < 65536) {
                if(flags[tmp]) {
                    return nums[j];
                } else {
                    flags[tmp] = 1;
                }
            }
        }
    }
    return -1;
}
