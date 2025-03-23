//
// Created by supanx on 25-3-7.
//
// 图的存储: 边集数组 邻接矩阵 邻接表(链式前向星)
/*
 *
 *
 */
#include <iostream>
using namespace std;
const int mx = 105;  // 最大 mx 个顶点
const int inf = 1e8;  // 权值上限

// 邻接矩阵存图
/*
 * 存点: 顶点数组 v[i]; v[i] = x : 编号为 i 的顶点存的数据为 x
 * 存边: g[i][j]
 * ---- 有向图
 * 无权图: g[i][j] = 1 | 0; g[i][j] = 1 表示存在编号为 i 到 j 点的边, 0 表示不存在
 * 有权图: g[i][j] = w; 存在 i 到 j 边权为 w(w < inf) 的边, w = inf 便是不存在
 * 无向图: 无向图的一条边相当于有向图的两条 方向相反 权值相同 的边 g[i][j] = g[j][i] = w;
 *
 * ----
 * inf = 0x3f3f3f3f = 1e8 / 2 左右
 * inf = 0x7fffffff = 1e8  左右(int 的上限)
 * */
// 无向有权图 n 个顶点 m 条边
int v[mx]; // v[i] 表示编号为 i 的点 存储的数据
int g[mx][mx]; // g[i][j] 表示以 i 为起点, j 为终点的 边 的 权值 w
int n, m;
// DFS 遍历
/* DFS:
 * 1.首先选择一个顶点 v 为初始遍历的点
 * 2.搜索 v 的邻接点, 判断这些邻接点有没有被遍历过, 如果没有, 选取其中一个 u, 访问该邻接点, 依次重复.
 * 走到死胡同, 返回上一个点. 直到起点所在的(强连通)分量中的点全部被访问完为止.
 * 3.如果此时图中还有未访问过的点, 选取一个继续 DFS
 *
 */
int flag[mx]; // 标记数组 flag[i] = 1, 表示编号为 1 的点已经访问过
void g_dfs(int u) {
    cout << u << " ";
    flag[u] = 1;
    for (int i = 1; i <= n; i++) {
        if (g[u][i] != inf && flag[i] == 0) {
            g_dfs(i);
        }
    }
}
/* BFS:
 * 1.任选一个未被访问的点为初始遍历点 u, u 入队
 * 2.循环: 队列非空
 * 访问队首点, 队首出队, 如果 队首 的邻接点未被访问, 将其入队
 * 3.如果还有点未被访问, 任选一个点为起点 重复 1 2 3
 */
int q[mx], f, r;
void g_bfs(int u) {
    q[r] = u;
    flag[q[f]] = 1;
    r = (r + 1) % mx;
    while (r != f) {
        cout << q[f] << " ";
        for (int i = 1; i <= n; i++) {
            if (g[q[f]][i] != inf && flag[i] == 0) {
                q[r] = i;
                r = (r + 1) % mx;
                flag[i] = 1;
            }
        }
        f = (f + 1) % mx;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) g[i][j] = inf;
    for (int i = 1; i <= n; i++) cin >> v[i];
    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        cin >> g[x][y]; // x 和 y 之间边的权值
        g[y][x] = g[x][y];
//        cout << x << " " << y << " " << g[x][y] << endl;
    }
    for (int i = 1; i <= n; i++) {
//        if (flag[i] == 0) g_dfs(i);
        f = r = 1;
        if (flag[i] == 0) g_bfs(i);
    }
    return 0;
}
/*

8 9
2 11 7 6 8 3 3 5
1 2 3
1 3 11
2 4 5
2 5 6
3 6 6
3 7 8
4 8 9
5 8 15
6 7 13

*/