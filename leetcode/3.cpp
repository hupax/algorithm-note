//
// Created by 沙枭 on 24-5-23.
//
// 3. 无重复字符的最长子串
// https://leetcode.cn/problems/longest-substring-without-repeating-characters/
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
 public:
  static int lengthOfLongestSubstring(string s)
  {
      int l = 0, ans = 0;
      vector<int> vis(128, -1);
      for (int i = 0; i < s.size(); ++i) {
          l = max(vis[s[i]] + 1, l);
          vis[s[i]] = i;
          ans = max(ans, i - l + 1);
      }
      return ans;
  }
};
int main()
{
    string s = "SFSDFS";
    std::reverse(s.begin(), s.end());
    cout << Solution::lengthOfLongestSubstring("abcabcbb") << endl;
}