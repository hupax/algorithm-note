//
// Created by supanx on 25-3-18.
//
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
int n, m;  // m个物品,容量为n
int w[105], v[105];
int dp[105][1005]; // 两个参数 记忆化
int dfs(int mi, int rc) { // 在 mi 个物品中选出体积不超过 rc 的最大价值
    if (mi == 0) return 0; // 物品选完了
    // 选和不选
    if (dp[mi][rc] != -1) return dp[mi][rc];
    int sumv1 = 0, sumv2 = 0;
    if (rc >= w[mi]) { // 选
        sumv1 = dfs(mi - 1, rc - w[mi]) + v[mi]; // 已有的价值加当前选的价值
    }
    sumv2 = dfs(mi - 1, rc);
    return dp[mi][rc] = max(sumv1, sumv2);
}
int main() {
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= m; i++) cin >> w[i] >> v[i];
    cout << dfs(m, n);
    return 0;
}
/*
70 3
71 100
69 1
1 2
*/ // ans = 3