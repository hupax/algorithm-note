//
// Created by hupax on 25-3-25.
//
#include <iostream>
#include <queue>
#define foi(x, y) for (int i=x; i<=y; i++)
#define foj(x, y) for (int j=x; j<=y; j++)
using namespace std;

int dx[4]={1, 0, 0, -1};
int dy[4]={0, -1, 1, 0};
char op[4]={'D', 'L', 'R', 'U'};
char map[35][55], o[35][55]; // o[i][j] 表示上一个点到(i, j)是通过o[i][j]方式
//int prex[35][55]; // prex[i][j]: (i, j)上一点的x坐标
//int prey[35][55]; // prey[i][j]:
int vis[35][55]; // prey[i][j]:
char ans[1555];
queue<pair<int, int>> q;
int main() {
    foi(1, 30) {
        foj(1, 50) map[i][j]=getchar();
        getchar();
    }
//    prex[1][1]=prey[1][1]=vis[1][1]=1;
    q.push({1, 1});
    while (!q.empty()) {
        auto [x, y]=q.front();q.pop();
        if (x==30&&y==50) break;
        foi(0, 3) {
            int nx=x+dx[i], ny=y+dy[i];
            if (nx<=0 || nx>30 || ny<=0 || ny>50 || map[nx][ny]!='0' || vis[nx][ny]) continue;
            o[nx][ny]=op[i];
            vis[nx][ny]=1;
            q.push({nx, ny});
        }
    }
    foi(1, 30) {
        foj(1, 50) cout<<map[i][j];
        cout<<endl;
    }
    int px=30, py=50, p=0;
    while (px!=1||py!=1) {
        cout << px << " " << py << endl;
        char ch=o[px][py];
        ans[p++]=ch;
        if (ch=='D') px-=1;
        else if (ch=='U') px+=1;
        else if (ch=='L') py+=1;
        else if (ch=='R') py-=1;
//        px=prex[px][py];
//        py=prey[px][py];
    }
    while (p--) cout << ans[p];
    return 0;
}