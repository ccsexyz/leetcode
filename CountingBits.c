// https://leetcode.com/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret;
        ret.reserve(num + 1);
        ret.push_back(0);
        int begin = 0, length = 1;
        for (int i = 1; i <= num; i++) {
            if (i == begin + length) {
                begin = length = i;
                ret.push_back(1);
                continue;
            }
            int off = i - begin;
            if (off) {
                ret.push_back(1 + ret[off]);
            } else {
                ret.push_back(0 + ret[off]);
            }
        }
        return ret;
    }
};

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *countBits(int num, int *returnSize) {
    int *ret = malloc(sizeof(int) * (++num));
    ret[0] = 0;
    int begin = 0, sum = 1;
    for (int i = 1; i < num; i++) {
        if (i == sum) {
            begin = i;
            sum = 2 * i;
            ret[i] = 1;
        } else {
            int off = i - begin;
            if (off) {
                ret[i] = 1 + ret[off];
            } else {
                ret[i] = ret[off];
            }
        }
    }
    *returnSize = num;
    return ret;
}
