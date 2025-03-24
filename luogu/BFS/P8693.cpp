//
// Created by supanx on 25-3-15.
// [蓝桥杯 2019 国 AC] 大胖子走迷宫
#include <iostream>
#include <queue>
#include <bitset>
using namespace std;
const int maxx = 305;
int n, k;/*flag = 2*/  // flag 表示此时的状态
char map[maxx][maxx];     // 地图
bitset<maxx> f[maxx];      // 标记数组
//int f[maxx][maxx];      // 标记数组
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
struct node {
  int x;
  int y;
  int tm;
};
queue<node> q;    // 队列
int bfs() {
    q.push({3, 3, 0}); // 起点入队
    f[3][3] = 1;        // 标记起点
    int flag = 2;
    while (!q.empty()) {
        node cur = q.front();
        q.pop();
        // 根据 tm 判断状态
//        int flag = cur.tm == k ? 1 : cur.tm >= 2*k ? 0 : 2;
        if (cur.tm == k) flag = 1;
        if (cur.tm == 2*k) flag = 0;
        if (flag != 0) q.push({cur.x, cur.y, cur.tm+1});
        for (int i = 0; i < 4; i++) {
            int nx = cur.x+dx[i], ny = cur.y+dy[i];  // 下一个区域
            if (nx > 0 && nx <= n && ny > 0 && ny <= n && !f[nx][ny] && map[nx][ny] == '+') {
                int tr = 1;
                for (int row = nx-flag; tr && row <= nx+flag; row++)
                    for (int col = ny-flag; tr && col <= ny+flag; col++)
                        if (row < 1 || row > n || col < 1 || col > n || map[row][col] == '*')
                            tr = 0;
                if (tr) {
                    if (nx == n-2 && ny == n-2) return cur.tm+1;
                    q.push({nx, ny, cur.tm+1});
                    f[nx][ny] = 1;
                }
            }
        }
    }
}
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) scanf("%s", &map[i][1]);
    cout << bfs();
    return 0;
}
