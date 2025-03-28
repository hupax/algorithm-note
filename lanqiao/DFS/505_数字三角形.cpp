//
// Created by hupax on 25-3-26.
//
#include <iostream>
using namespace std;
const int N=105;
int n, m[N][N], dp[N][N], ans;

int dfs(int cnt, int c, int l, int r, int sum) {
    if (cnt==n) {
        return sum;
    }
    int mx=0;
    // 左走右
    if (n/2-r>0) mx=dfs(cnt+1, c+1, l, r+1, sum+m[cnt+1][c+1]);
    if (n/2-l>0) mx=max(mx, dfs(cnt+1, c, l+1, r, sum+m[cnt+1][c]));
    return mx;
}
int main() {
    cin >> n;
    for (int i=1; i<=n; i++) for (int j=1; j<=i; j++) cin>>m[i][j];
//    cout<<dfs(1, 1, 0, 0, m[1][1]);
    dp[1][1]=m[1][1];
    for (int i=2; i<=n; i++) for (int j=1; j<=i; j++) {
        dp[i][j]=max(dp[i-1][j-1], dp[i-1][j])+m[i][j];
    }
    ans=(n&1)?dp[n][n/2+1]:max(dp[n][n/2], dp[n][n/2+1]);
    cout<<ans;
    
    
    return 0;
}