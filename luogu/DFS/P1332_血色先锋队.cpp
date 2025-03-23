//
// Created by supanx on 25-3-18.
// TODO 老实去用queue
#include <iostream>
#define fo(x, y) for (int i=x; i<=y; i++)
#define foo(x, y) for (int j=x; j<=y; j++)
using namespace std;
int read() {
    int x=0;
    char ch=getchar();
    while (isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return x;
}
void wr(int x) {
    if (x>9) wr(x/10);
    putchar(x%10+'0');
}
const int maxn = 505;
int n, m, a, b, f, r, vis[maxn][maxn], map[maxn][maxn], qx[maxn*maxn], qy[maxn*maxn];
// 方向数组
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int main() {
    n=read(),m=read(),a=read(),b=read();
    f=r=0;
    fo(1, a) {
        qx[r]=read(), qy[r]=read();
        vis[qx[r]][qy[r]]=1;
        map[qx[r]][qy[r]]=0;
        r=(r+1)%maxn;
    }
    // bfs
    while (f != r) {
        int x = qx[f], y = qy[f];
        f=(f+1)%maxn;
        for (int i = 0; i < 4; i++) {
            int nx = x+dx[i], ny = y+dy[i];
            if (nx<=0 || nx>n || ny<=0 || ny>m || vis[nx][ny]) continue;
            qx[r] = nx, qy[r] = ny;
            r = (r+1)%maxn;
            vis[nx][ny]=1;
            map[nx][ny] = map[x][y]+1;
        }
    }
    int x, y;
    fo(1, b) {
        x=read(), y=read();
        wr(map[x][y]?map[x][y]:0);
        cout << endl;
    }
    return 0;
}