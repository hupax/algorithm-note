//
// Created by hupax on 25-3-26.
//
#include <iostream>
using namespace std;
const int N=105;
int n, m[N][N], dp[N][N]={-1};

int dfs(int cnt, int c, int l, int r, int sum) {
    if (cnt==n) {
        return sum;
    }
    int mx=0;
    if (dp[l][r]!=-1) return dp[l][r];
    // 左走右
    if (n/2-r>0) mx=dfs(cnt+1, c+1, l, r+1, sum+m[cnt+1][c+1]);
    if (n/2-l>0) mx=max(mx, dfs(cnt+1, c, l+1, r, sum+m[cnt+1][c]));
    dp[l][r]=max(dp[l][r], mx);
    return dp[l][r];
    
}
int main() {
    cin >> n;
    for (int i=1; i <= n; i++) for (int j=1; j <= i; j++) cin>>m[i][j];
    cout<<dfs(1, 1, 0, 0, m[1][1]);
    
    return 0;
}