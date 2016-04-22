// https://leetcode.com/problems/gray-code/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize) {
    int size_ = 1 << n;
    int *ret = malloc(sizeof(int) * (size_));
    *returnSize = size_;
    for(int i = 0; i < size_; i++) {
        ret[i] = (i >> 1) ^ i;
    }
    return ret;
}
