//
// Created by supanx on 25-3-8.
//
#include <iostream>
//#include <vector>
#include <queue>
using namespace std;
const int mx = 105;

/* 给定一个带权无向图, 含有 n 个顶点 m(m >= n - 1) 条边, 权值为 w, w <= n<= 100;
 * 求改图最小生成树
 * 最小生成树: 在该图中选出 n 个点, n - 1 条边组成生成树, 并使得这 n - 1 条边的权值和最小
 * krukal 算法: (选边)
 * 1.n - 1条边的权值和最小: 将边按的边的权值升序排序(小到大), 选 n - 1次,
 * 每次选权值最小并且没有被选过的边.
 * 2.选边: n - 1 条边要是 n 个点连通 即 ---> 没有成环 ---> 判断有没有成环
 * 判断: 边的起点和终点是否已经连通? 如果已经连通, 说明存在一条路径使得这条的 起点 和 终点 连通
 * 此时再选这条边就会成环
 * ----> 判断这条边的 起点 和 终点 是否连通 ---> 判断 ---> 这两个点是否属于同一个生成树 ---> 并查集
 * 用并查集:
 * 初始: 每个点相互独立, 看成一棵树
 * 选边: 选出权值最小且没有选过的边 x----y, 判断 x y 是否属于同一个棵树
 *  1.x y不属于同一个棵树: 说明可以选, 将 x y 合并
 *  2.x y属于同一棵树: 说明 x y 已经连通, 不可以选;
 */

int n, m;
int v[mx];
struct ENode {
  int st;
  int ed;
  int w;
  bool operator<(const ENode &b) const {
      return w > b.w;
  }
};
int f[mx];
int find_f(int x) { // 找 x 的根节点
    if (f[x] == x) return x;
    return f[x] = find_f(f[x]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    priority_queue<ENode> e;
//    vector<ENode> e;
//    for (int i = 0; i <= n; i++) v[i] = i;
    int x, y, w;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> w;
        e.push({x, y, w});
    }
    for (int i = 0; i < n; i++) f[i] = i; // 初始化这 n 个节点为独立的树
    for (int i = 1; i < n; i++) {
        ENode p = e.top();
        e.pop();
        int fst = find_f(p.st);
        int fed = find_f(p.ed);
        while (fst == fed) {
            p = e.top();
            e.pop();
            fst = find_f(p.st);
            fed = find_f(p.ed);
        }
        f[fst] = fed;
        printf("st:%d en:%d w:%d\n", p.st, p.ed, p.w);
    }
    return 0;
}

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