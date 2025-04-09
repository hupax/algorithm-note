//
// Created by hupax on 25-4-8.
//
#include <bits/stdc++.h>
#define inf 1e5
using namespace std;
const int N=105;
int n, m; // n个点 m条边
int a[N][N]; // a[i][j]=w 表示 i j 之间有一条权值为 w
int dp[N][N]; // dp[i][j]=x 表示 i到j最短距离为x
int main() {
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++) {
            a[i][j]=i==j?0:inf;
            dp[i][j]=a[i][j];
        }
    int x, y, w;
    for (int i=1; i<=m; i++) {
        cin>>x>>y>>w;
        a[x][y]=dp[x][y]=w;
    }
    for (int k=1; k<=n; k++) { // 枚举中转点
        for (int i=1; i<=n; i++) { // 枚举起点
            for (int j=1; j<=n; j++) { // 枚举终点
                dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }
    
    for (int i=1; i <= n; i++) {
        for (int j=1; j <= n; j++) {
            printf("%6d ", dp[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
}

/*
 *
5 7
1 3 1
1 5 10
2 5 5
2 4 1
3 2 1
3 5 7
4 5 1
 
 
     0      2      1      3      4
100000      0 100000      1      2
100000      1      0      2      3
100000 100000 100000      0      1
100000 100000 100000 100000      0
 
 */