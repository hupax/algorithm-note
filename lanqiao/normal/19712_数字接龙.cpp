//
// Created by hupax on 25-4-8.
//
#include <bits/stdc++.h>
using namespace std;
const int N=15;
int n, k;
int a[N][N], mid[2*N][2*N], vis[N][N];
int dx[8]={-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8]={0, 1, 1, 1, 0, -1, -1, -1};
string dfs(int x,int y, int stp, string p) {
    if (stp==n*n && x==n && y==n) return p;
    
    for (int i=0; i<8; i++) {
        int nx=x+dx[i], ny=y+dy[i];
        if (nx<=0 || nx>n || ny<=0 || ny>n) continue;
        if (vis[nx][ny] || a[nx][ny]!=stp%k) continue;
        int mx=x*2+dx[i], my=y*2+dy[i];
        if ((i&1)&&mid[mx][my]) continue;
        if (i&1) mid[mx][my]=1;
        vis[nx][ny]=1;
        string res=dfs(nx, ny, stp+1, p+char(i^48));
        if (!res.empty()) return res;
        vis[nx][ny]=0;
        if (i&1) mid[mx][my]=0;
    }
    return "";
}
int main() {
    cin>>n>>k;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) cin>>a[i][j];
    vis[1][1]=1;
    string ans=dfs(1, 1, 1, "");
    if (ans.empty()) cout << -1;
    else cout << ans;
    
    return 0;
}