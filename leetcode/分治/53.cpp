//
// Created by supanx on 25-3-14.
//
// 最大子数组和
// 分治
#include <iostream>
#include <vector>
using namespace std;

int msa(vector<int> &nums, int l, int r) {
    int mid = (l + r) / 2;
    if (l == r) {
        return nums[l];
    }
    int lmax, rmax, mmax;
    lmax = rmax = mmax = INTMAX_MIN;
    for (int i = l; i < mid; i++) {
        mmax = max(mmax, mmax + nums[i]);
    }
    for (int i = mid; i <= r; i++) {
        mmax = max(mmax, mmax + nums[i]);
    }
    for (int i = l; i <= mid; i++) {
        lmax = max(lmax, lmax + nums[i]);
    }
    for (int i = r; i > mid; i--) {
        rmax = max(rmax, rmax + nums[i]);
    }
    return max(max(rmax + lmax, mmax), msa(nums, l))
}
int maxSubArray(vector<int> &nums) {
    int n = nums.size();
    int l = 0, r = n - 1;
    return msa(nums, l, r);
}
int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums);
    
    return 0;
}