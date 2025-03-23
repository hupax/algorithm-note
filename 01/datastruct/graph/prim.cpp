//
// Created by supanx on 25-3-8.
//
#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int mx = 105;
const int inf = 1e3;

/* 给定一个带权无向图, 含有 n 个顶点 m(m >= n - 1) 条边, 权值为 w, w <= n<= 100;
 * 求该图最小生成树
 * 最小生成树: 在该图中选出 n 个点, n - 1 条边组成生成树, 并使得这 n - 1 条边的权值和最小
 *
 * prime 算法: (|V|^2)
 * 从选点的角度, 每次选择离 生成树最近(权值最小) 的点
 * 1.把所有点分为:
 * A:已经加入生成树的点.
 * B:未加入生成树的点.
 * 点 x 到生成树的最小距离 dist: 如果点 X 与生成树的点(A类点)有多个边相连, 最小权值的边即为最小 dist.
 * 如果没有与生成树相连的边, 认为 X 到生成树的距离为 无穷大.
 *
 * 2.选点:
 *  1.第一个点任选一个点 X, 变为A类点, 更新 X 邻接点到生成树的最小距离 dist.
 *  2.循环 n - 1 次, 每次从 B 类中选一个离生成树最近的点 X, 变为 A类点, 如果 X 邻接点到生成树的距离
 *  小于到 X 点的距离, 则更新这些点到生成树的最小距离为到 X 的距离.
 *
 * 实现:
 * 1.维护一个 dist[] 数组. dist[i] = d 表示 i 点到生成树的最小距离为 d
 * 2.使用一个 flag[] 数组区分 A类点 和 B类点, flag[i] = 0 表示 i 点还未加入生成树
 *  1.给定一个点 s 为起点, flag[s] = 1; 更新 s 的邻接点到生成树的最小距离 dist[i].
 *  2.循环 n - 1 次:
 *   (1).选出 flag == 0 并且 dist 最小的点 X; (2).flag[x] = 1; (3).更新 X 的邻接点的 dist;
 *
 * adj[i] = j // i 点离生成树最近的点为 j 点.
 */
int n, m, flag[mx];
struct ENode {
  int st, ed, w, mds;
  bool operator<(const ENode &b) const {
      return mds < b.mds;
  }
};
multiset<ENode> ms;
vector<vector<int>> g;
// TODO 使用STL实现 O(NlogN)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    int x, y, w;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> w;
        g[x][y] = ++g[y][x];    // 表示 x 到 y , y 到 x 边的数量
        ms.insert({x, y, w, inf});
    }
    // 任选一个初始点 s
    int s = 0;
    flag[s] = 1;
    
    
    return 0;
}

/*
int dist[mx], adj[mx];
int g[inf][inf];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    int x, y, w;
    fill(g[0], g[0] + inf * inf, inf);
    for (int i = 0; i < m; i++) {
        adj[i] = i;
        dist[i] = inf;
        cin >> x >> y >> w;
        g[x][y] = g[y][x] = w;
    }
    
    flag[0] = 1;
    dist[0] = 0;
    for (int i = 0; i < n; i++) {
        if (g[0][i] != inf) {
            if (dist[i] > g[0][i]) {
                adj[i] = 0;
                dist[i] = g[0][i];
            }
        }
    }
    for (int i = 1; i < n; i++) {
        // 找出 flag == 0 并且 离生成树最小的点 p
        int mdt = inf;
        int p;
        for (int j = 0; j < n; j++) {
            if (dist[j] < mdt && flag[j] == 0) {
                mdt = dist[j];
                p = j;
            }
        }
        flag[p] = 1;
        dist[p] = 0;
        cout << p << "离生成树最近的点:" << adj[p] << " 距离为:" << mdt << endl;
        // 更新 p 邻接点到生成树的最小距离
        for (int k = 0; k < n; k++) {
            if (g[p][k] != inf && flag[k] == 0) {
                if (dist[k] > g[p][k]) {
                    dist[k] = g[p][k];
                    adj[k] = p;
                }
            }
        }
    }
    
    return 0;
}*/

/*
9 15
0 1 3
0 5 4
1 6 6
6 5 7
1 2 8
1 8 5
2 8 2
2 3 12
8 3 11
6 3 14
6 7 9
5 4 18
3 7 6
7 4 1
3 4 10
*/