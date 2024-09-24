//
// Created by 沙枭 on 2024/4/25.
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<int> w;
vector<int> v;
vector<vector<int>> dp;
int main()
{
    cin >> m >> n;
    w.resize(n + 1, 0);
    v.resize(n + 1, 0);
    dp.resize(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (j < w[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[n][m];
  // 请在此输入您的代码
  return 0;
}
/*
10 4
2 8
3 3
4 5
7 1
 */