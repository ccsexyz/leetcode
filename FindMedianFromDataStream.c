// https://leetcode.com/problems/find-median-from-data-stream/

// 基本思路：
// 用1个大顶堆来保存中点左边的数，用一个小顶堆来保存中点右边的数

class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if(flag_ == false) {
            flag_ = true;
            mid_ = num;
            if(left_.empty()) return;
            if(num < left_[0]) {
                pop_heap(left_.begin(), left_.end());
                swap(mid_, left_.back());
                push_heap(left_.begin(), left_.end());
            } else if(num > right_[0]) {
                pop_heap(right_.begin(), right_.end(), greater<int>());
                swap(mid_, right_.back());
                push_heap(right_.begin(), right_.end(), greater<int>());
            }
        } else {
            flag_ = false;
            left_.push_back(mid_ > num ? num : mid_);
            right_.push_back(mid_ > num ? mid_ : num);
            push_heap(left_.begin(), left_.end());
            push_heap(right_.begin(), right_.end(), greater<int>());
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(flag_) {
            return mid_;
        } else {
            return (left_[0] + right_[0]) / 2.0;
        }
    }
private:
    bool flag_ = false;
    int mid_ = 0;
    vector<int> left_;
    vector<int> right_;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
