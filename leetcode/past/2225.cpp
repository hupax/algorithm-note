//
// Created by 沙枭 on 24-5-22.
//
// 2225. 找出输掉零场或一场比赛的玩家
// https://leetcode.cn/problems/find-players-with-zero-or-one-losses/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
 public:
  vector<vector<int>> findWinners(vector<vector<int>> &matches)
  {
      unordered_map<int, int> lowers;
      unordered_map<int, int> fw;
      unordered_map<int, int> fl;
      for (auto &i : matches) {
          lowers[i[1]]++;
          fw[i[0]] = 1;
          fl[i[1]] = 1;
      }
      vector<vector<int>> ans(2);
      for (auto &i : matches) {
          if (fw[i[0]]) {
              if (lowers.find(i[0]) == lowers.end()) {
                  ans[0].push_back(i[0]);
              }
              else if (lowers[i[0]] == 1) {
                  ans[1].push_back(i[0]);
              }
          }
          if (lowers[i[1]] == 1 && fl[i[0]]) {
              ans[1].push_back(i[1]);
          }
          fw[i[0]] = 0;
          fw[i[1]] = 0;
      }
      sort(ans[0].begin(), ans[0].end(), [](int &a, int &b)
      {
        return a < b;
      });
      sort(ans[1].begin(), ans[1].end(), [](int &a, int &b)
      {
        return a < b;
      });
      return ans;
  }
};

/*
示例 1：

输入：matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
输出：[[1,2,10],[4,5,7,8]]
解释：
玩家 1、2 和 10 都没有输掉任何比赛。
玩家 4、5、7 和 8 每个都输掉一场比赛。
玩家 3、6 和 9 每个都输掉两场比赛。
因此，answer[0] = [1,2,10] 和 answer[1] = [4,5,7,8] 。
示例 2：

输入：matches = [[2,3],[1,3],[5,4],[6,4]]
输出：[[1,2,5,6],[]]
解释：
玩家 1、2、5 和 6 都没有输掉任何比赛。
玩家 3 和 4 每个都输掉两场比赛。
因此，answer[0] = [1,2,5,6] 和 answer[1] = [] 。


提示：

1 <= matches.length <= 105
matches[i].length == 2
1 <= winneri, loseri <= 105
winneri != loseri
所有 matches[i] 互不相同
 
 */