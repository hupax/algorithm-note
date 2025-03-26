//
// Created by hupax on 25-3-25.
//
#include <iostream>
using namespace std;
#define fo(a, b) for (int i=a; i<=b; i++)
const int N=25;
int n, a[N], b[N];
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};
int ans[N*N], len=0, vis[N*N], su=0;
inline int check() {
    fo(0, n-2) if (a[i]||b[i]) return 0;
    if (a[n-1]==1&&b[n-1]==1) return 1;
    return 0;
}
void dfs(int x, int y) {
    if (x==n-1&&y==n-1) {
        if (check()) {
            for (int i=0; i<len; i++)cout<<ans[i]<<" ";
            cout << x*n+y;
        }
        return;
    }
    int p=x*n+y;
    vis[p]=1;
    a[x]--, b[y]--;
    ans[len++]=p;
    for (int i=0; i<4; i++) {
        int nx=x+dx[i], ny=y+dy[i];
        if (nx<0 || nx>=n || ny<0 || ny>=n || vis[nx*n+ny]) continue;
        if (!a[nx]||!b[ny]) continue;
        dfs(nx, ny);
    }
    vis[p]=0;
    a[x]++, b[y]++;
    len--;
}
int main() {
    cin>>n;
    fo(0, n-1) cin>>b[i];
    fo(0, n-1) cin>>a[i];
    dfs(0, 0);
    
    return 0;
}