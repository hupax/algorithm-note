//
// Created by hupax on 25-4-6.
//
#include <bits/stdc++.h>
using namespace std;
const int N=10;
int a[N][N];
int dx[4]={0, 1, 1, -1};
int dy[4]={1, 0, 1, 1};
int check(int x,int y, int f) {
    for (int d=0; d<4; d++) {
        int cnt=1;
        for (int i=1; i<5; i++) {
            int nx=x+dx[d]*i, ny=y+dy[d]*i;
            if (nx < 1 || nx > 5 || ny < 1 || ny > 5) break;
            if (a[nx][ny]==f) cnt++;
            else break;
        }
        for (int i=1; i<5; i++) {
            int nx=x-dx[d]*i, ny=y-dy[d]*i;
            if (nx < 1 || nx > 5 || ny < 1 || ny > 5) break;
            if (a[nx][ny]==f) cnt++;
            else break;
        }
        if (cnt>=5) return 1;
    }
    return 0;
}
int ans=0;
void dfs(int stp) {
    if (stp==26) {
        ans++; return;
    }
    for (int i=1; i<=5; i++) {
        for (int j=1; j<=5; j++) {
            if (a[i][j]!=-1) continue;
            a[i][j]=stp&1;
            if (check(i, j, stp&1)) {
                a[i][j]=-1;
                continue;
            }
            dfs(stp+1);
            a[i][j]=-1;
        }
    }
}
int main() {
    memset(a, -1, sizeof(a));
    dfs(1);
    cout<<ans;
    
    return 0;
}