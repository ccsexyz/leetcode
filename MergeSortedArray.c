// https://leetcode.com/problems/merge-sorted-array/

void merge(int* nums1, int m, int* nums2, int n) {
    int *nums3 = malloc(sizeof(int) * m);
    memcpy(nums3, nums1, sizeof(int) * m);
    int i = 0, j = 0;
    while(i != m && j != n) {
        if(nums3[i] < nums2[j]) {
            nums1[i + j] = nums3[i];
            i++;
        } else {
            nums1[i + j] = nums2[j];
            j++;
        }
    }
    if(i == m) {
        for(; j < n; j++) {
            nums1[i + j] = nums2[j];
        }
    } else {
        for(; i < m; i++) {
            nums1[i + j] = nums3[i];
        }
    }
}
