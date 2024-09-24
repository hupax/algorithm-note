//
// Created by 沙枭 on 2024/4/24.
//
// 01背包
#include <iostream>
#include <bits/stdc++.h>

const int M = 305;

using namespace std;

int v[305], w[305], dp[M][M];
// dp数组定义在主函数外，里面元素自动归0;
// 边界就有了;
int main()
{
    int m, n;
    cin >> m >> n; // 背包容量m<= 300, 物品数n<=31;
    for (int i = 1; i <= n; ++i)
        cin >> w[i] >> v[i];
    for (int i = 1; i <= n; ++i) // 每层循环多一个物品i可以选择;
    {
        for (int j = 1; j <= m; ++j)  // 遍历背包容量;
        {
            if (j < w[i])   // 放不下;
                dp[i][j] = dp[i - 1][j]; // 继承上一层状态;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            // 在上一层状态和选了物品i后的最大值做选择;
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << dp[n][m] << endl;
    return 0;
}
/*
10 4
2 1
3 3
4 5
7 9
 */
