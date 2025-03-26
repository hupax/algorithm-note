//
// Created by hupax on 25-3-25.
//
#include <iostream>
using namespace std;
int ans=0;
int map[9][9];
int vis[9][9];
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};
void dfs(int cnt, int x, int y) {
    if (x<=0 || x>4 || y<=0 || y>4 || vis[x][y]) return;
    if (cnt==16) {
        ans++;
        return;
    }
    vis[x][y]=1;
    for (int i=0; i<=3; i++) {
        int nx=x+dx[i], ny=y+dy[i];
        dfs(cnt+1, nx, ny);
    }
    vis[x][y]=0;
}
int main() {
    for (int i=1; i<=4; i++) {
        for (int j=1; j<=4; j++) {
            dfs(1, i, j);
        }
    }
//    dfs(1, 1, 1);
    cout<<ans;
    return 0;
}