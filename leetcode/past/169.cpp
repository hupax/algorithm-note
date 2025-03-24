//
// Created by 沙枭 on 24-5-24.
//
// 169. 多数元素
// https://leetcode.cn/problems/majority-element/
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution
{
 public:
  static int majorityElement(vector<int> &nums)
  {
      int ans, e = 0;
      unordered_map<int, int> vis;
      for (auto i : nums) {
          vis[i]++;
          if (vis[i] > e) {
              e = vis[i];
              ans = i;
          }
      }
      return ans;
  }
};