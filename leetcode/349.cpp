//
// Created by 沙枭 on 24-5-26.
//
// 349. 两个数组的交集
// https://leetcode.cn/problems/intersection-of-two-arrays/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution
{
 public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
  {
//      set<int> set1(nums1.begin(), nums1.end());
//      set<int> set2(nums2.begin(), nums2.end());
//      sort(nums1.begin(), nums1.end());
//      sort(nums2.begin(), nums2.end());
//      vector<int> ans;
//      int i = 0, j = 0;
//      while (i < nums1.size() && j < nums2.size()) {
//          if (nums1[i] > nums2[j]) {
//              j++;
//          }
//          else if (nums2[j] > nums1[i]) {
//              i++;
//          }
//          else {
//              if (ans.empty() || ans.back() != nums1[i]) {
//                  ans.push_back(nums1[i]);
//              }
//              i++;
//              j++;
//          }
//      }
//      set_intersection(set1.begin(), set1.end(),
//                       set2.begin(), set2.end(),
//                       back_inserter(ans));
    unordered_set<int> set2(nums2.begin(), nums2.end());
    unordered_set<int> ans;
    for (auto num : nums1) {
        if (set2.count(num)) {
            ans.insert(num);
        }
    }
      return vector<int> (ans.begin(), ans.end());
  }
};