//
// Created by hupax on 25-4-6.
//
#include <bits/stdc++.h>
using namespace std;
const int N=305;
int n, sum[N], dp[N][N];
int main() {
    cin>>n;
    memset(dp, 0x3f, sizeof(dp));
    for (int i=1; i<=n; i++) {
        cin>>sum[i];
        sum[i]+=sum[i-1];
        dp[i][i]=0;
    }
    int j;
    // 枚举区间长度
    for (int len=2; len<=n; len++) {
        // 枚举左端点
        for (int i=1; i+len-1<=n; i++) {
            // 右端点
            j=i+len-1;
            // 枚举分割点
            for (int k=i; k<j; k++) {
                dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]+(sum[j]-sum[i-1]));
            }
        }
    }
    cout<<dp[1][n];
    
    return 0;
}