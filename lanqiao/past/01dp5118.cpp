//
// Created by 沙枭 on 2024/4/24.
//
// 小兰的神秘礼物
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int m, link;
int x[1005], dp[1005][1005];
int main()
{
    cin >> m >> link;
    for (int i = 1; i <= link; ++i)
        cin >> x[i];
    for (int i = 1; i <= link; ++i)
        for (int j = 1; j <= m; ++j)
            if (j < x[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - x[i]] + x[i]);
     cout << m - dp[link][m] << endl;
  // 请在此输入您的代码
  return 0;
}