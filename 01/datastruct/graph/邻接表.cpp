//
// Created by supanx on 25-3-8.
//
#include <iostream>
using namespace std;
const int mx = 105;  // 最大 mx 个顶点
const int inf = 1e8;  // 权值上限

/*
 *邻接表存图:
 *
 */

// 带权无向图
// 带权边结构体
struct ENode {
     int adj;   // 表示该边终点的下标
     int w;
     ENode* next;
};

// 图
struct GNode {
  int data; // 该点的数据
  ENode* first; // 连接改点的边, 以改点为起点的边 (指向该顶点的边表)
} g[mx];

int n, m; // n 个顶点 m 条边
int flag[mx];
// DFS
void g_dfs(int u) {
    cout << u << " ";
    flag[u] = 1;
    ENode* p = g[u].first;
    while (p && flag[p->adj] == 0) {
        g_dfs(p->adj);
        p = p->next;
    }
}
// BFS
int f, r;
void g_bfs(int u) {
    GNode q[mx];
    q[r] = g[u];
    flag[u] = 1;
    r = (r + 1) % mx;
    while (r != f) {
        cout << q[f].data << " ";
        ENode* p = q[f].first;
        while (p) {
            if (flag[p->adj] == 0) {
                q[r] = g[p->adj];
                r = (r + 1) % mx;
                flag[p->adj] = 1;
            }
            p = p->next;
        }
        f = (f + 1) % mx;
    }
    
}
int main() {
    ios::sync_with_stdio(false);
      cin.tie(nullptr);
      
      cin >> n >> m;
      for (int i = 1; i <= n; i++) cin >> g[i].data;
      int x, y, w; // 编号为 x, y 的点
      for (int i = 1; i <= m; i++) {
          cin >> x >> y >> w;   // 表示 x 和 y 之间权值为 w
          // 将 y 加入到 x 的后面
          ENode* s = new ENode({y, w, nullptr});
          s->next = g[x].first;
          g[x].first = s;
          
          // 将 x 加入到 y 的后面
          s = new ENode({x, w, nullptr});
          s->next = g[y].first;
          g[y].first = s;
      }
      for (int i = 1; i <= n; i++) {
//          if (flag[i] == 0) g_dfs(i);
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