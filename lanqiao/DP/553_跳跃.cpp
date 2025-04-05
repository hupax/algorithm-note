//
// Created by hupax on 25-4-5.
//
#include <iostream>
using namespace std;
const int N=105;
const int M=-1e4-5;
int n, m, a[N][N], dp[N][N];
int main() {
    cin>>n>>m;
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cin>>a[i][j], dp[i][j]=M;
    dp[1][1]=a[1][1];
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            for (int k=1; k<3&&i-k>0; k++) {
                dp[i][j]=max(dp[i][j], dp[i-k][j]+a[i][j]);
            }
            for (int k=1; k<3&&j-k>0; k++) {
                dp[i][j]=max(dp[i][j], dp[i][j-k]+a[i][j]);
            }
//            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
//    cout<<dp[n][m];
//
    return 0;
}

/*
 dp[i][j]=
 
 dp[i-1][j]=a
 dp[i-2][j]=b
 dp[i-3][j]=c

 dp[i][j-1]=d
 dp[i][j-2]=e
 dp[i][j-3]=f
 
 */