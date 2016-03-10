// https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArray(vector<int> &nums) {
        int size = nums.size();
        if(size == 0) {
            return 0;
        }
        if(size % 2 == 0) {
            return ((double)nums[size / 2] + nums[size / 2 - 1]) / 2;
        } else {
            return nums[size / 2];
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty()) {
            return findMedianSortedArray(nums2);
        } else if(nums2.empty()) {
            return findMedianSortedArray(nums1);
        }
        if(nums1.back() > nums2.back()) return findMedianSortedArrays(nums2, nums1);
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<int> ret;
        ret.reserve(size1 + size2);
        int j = 0;
        for(int i = 0; i < size2 ; i++) {
            if(j < size1) {
                for(; j < size1 && nums1[j] <= nums2[i]; j++) ret.push_back(nums1[j]);
            }
            ret.push_back(nums2[i]);
        }
        return findMedianSortedArray(ret);
    }
};
