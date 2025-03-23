//
// Created by supanx on 25-3-10.
//
#include <iostream>
#include <string>
using namespace std;
/* 拓扑排序: 根据有向无环图构造拓扑序列的过程
 * 1.拓扑序列: 通过 AOV 网得到一个活动之间的先后次序/序列 即为拓扑序列 (
 * 点的前驱一定被先访问)
 *
 * 给出 n(n < 100) 个点 m 条边的有向图, 求出该图的拓扑序列, 如果有环输出 -1.
 * 1)选一个没有前驱的点 x 输出 ---> 入度为 0 的点.
 * 2)减去 x 所有的出边 --> 删除 x 邻接点的入边 ---> x 邻接点的入边 - 1
 * 重复 1) 2) n - 1 次
 *
 * 1.建图
 * 2.ind[] 和 存储拓扑序列的 ans[]
 * 3.ans 非空循环
 * 4.ind[i] --
 *
 */
const int maxx = 105;
int n, m;
int ind[maxx], ans[maxx], hi;
int g[maxx][maxx];

void topo() {
    hi = 1;
    // 初始时, 找出入度为 0 的点, 加入 ans
    for (int i = 1; i <= n; i++) {
        if (!ind[i]) ans[hi++] = i;
    }
    while (hi > 1) {
        hi--;
        cout << ans[hi] << " ";
        for (int i = 1; i <= n; i++) {
            if (g[ans[hi]][i]) {
                ind[i]--;
                if (!ind[i]) ans[hi++] = i;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        g[x][y] = 1;
        ind[y]++;
    }
    topo();
    return 0;
}
/*
6 8
1 2
1 3
1 4
3 2
3 5
4 5
6 4
6 5
 
 */