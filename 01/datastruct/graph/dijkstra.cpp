//
// Created by supanx on 25-3-10.
//
#include <iostream>
using namespace std;
/* 图的最短路径 dijkstra
 * 给定无向带权图, 图中有 n (n < 100) 个点, m (m < 10000) 条边, 权值为 w (w < 1000)
 * 求起点 s 到其他 n - 1 个点的最短路径的 长度 和 说经过的点 n - 1, n - 2 ... 1
 *
 * dijkstra :
 *  1.维护一个 dist 数组, dist[i] = x; 表示点 i 到 起点的最小距离为 x;
 *  2.flag[i] = 1/0 1:已经确定 i 点的最短路径, 存图: 邻接矩阵.
 *  3.path[i] = x, i 离 s 的最短路径中 x 是 i 的上一个点.
 *
 *  4.初始时 dist[s] = 0; dist[i] = g[s][j] (i 的邻接点边的权值), flag[s] = 1, path[j] = s;
 *  循环 n - 1 次,每次确定一个离 s 最近的点, 更新这个点的 dist, (离 s 的最短路径一定经过上一个离 s 的
 *  最近的点), path, flag
 */
const int maxv = 105, maxe = 5005, inf = 1005;

int n, m;
int dist[maxv], g[maxe][maxe], flag[maxv], path[maxv];

void dijkstra(int st) {
    // 初始时
    dist[st] = 0;
    flag[st] = 1;
    path[st] = st;
    // 确定 st 邻接点的最短路径长度
    for (int i = 0; i < n; i++) {
        if (g[st][i] < inf && flag[i] == 0) {
            dist[i] = g[st][i];
            path[i] = st;
        }
    }
    // 循环 n - 1 次
    for (int i = 1; i < n; i++) {
        // 确认的点
        int p = -1, minn = inf;
        for (int j = 0; j < n; j++) {
            if (dist[j] < minn && flag[j] == 0) {
                minn = dist[j];
                p = j;
            }
        }
        if (p == -1) return; // 没有没有确认的点了
        flag[p] = 1;
        // 更新路径长度
        for (int j = 0; j < n; j++) {
            if (g[p][j] + minn < dist[j] && flag[j] == 0) {
                path[j] = p;
                dist[j] = g[p][j] + minn;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        dist[i] = inf;
        for (int j = 0; j < n; j++) {
            g[i][j] = g[j][i] = inf;
        }
    }
    int x, y, w;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> w;
        g[x][y] = g[y][x] = w;
    }
    int st;
    cin >> st;
    dijkstra(st);
    
    for (int i = 0; i < n; i++) {
        printf("%d -> %d : %d\n", st, i, dist[i]);
        cout << "path: ";
        int p = i;
        while (p != path[p]) {
            cout << p << " <- ";
            p = path[p];
        }
        cout << endl;
    }
    
    return 0;
}
/*
9 16
0 1 1
0 2 5
1 2 3
1 3 7
1 4 5
2 4 1
2 5 7
3 4 2
3 6 3
4 5 3
4 6 6
4 7 9
5 7 5
6 7 2
6 8 7
7 8 4
0

0 -> 0 : 0
path:
0 -> 1 : 1
path: 1 <-
0 -> 2 : 4
path: 2 <- 1 <-
0 -> 3 : 7
path: 3 <- 4 <- 2 <- 1 <-
0 -> 4 : 5
path: 4 <- 2 <- 1 <-
0 -> 5 : 8
path: 5 <- 4 <- 2 <- 1 <-
0 -> 6 : 10
path: 6 <- 3 <- 4 <- 2 <- 1 <-
0 -> 7 : 12
path: 7 <- 6 <- 3 <- 4 <- 2 <- 1 <-
0 -> 8 : 16
path: 8 <- 7 <- 6 <- 3 <- 4 <- 2 <- 1 <-

*/