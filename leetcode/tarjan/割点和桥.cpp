//
// Created by hupax on 25-4-11.
//
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=1e3+5, M=2e4+5;

// 无向图, n个点m条边
int n, m;
// 星存图
struct E {
  int to, w, next;
} e[M];
int head[N];
int times=0, sta[N], p=0; // 时间戳 栈
/*
 * // dfn: i : DFS中, x点被访问的时间点
 * // low: j : x通过边(或者有向边)可回溯到的最早的时间点
 * // fa[i]=j: i的父亲是j
 */
int dfn[N], low[N], fa[N];
/*
 * 割点: case1: x不是root, x有孩子 && low[y]>=dfn[x]
 *       case2: x是root x有两个孩子(是搜索树中的两个孩子)
 * 桥: x->y 是桥  low[y] > dfn[x]
 */
vector<int> cp; // 割点
vector<pair<int, int>> bg; // 桥
void dfs(int x) { // x: 当前的点
    dfn[x]=low[x]=++times;
    int child=0;
    // 遍历x的邻接点
    for (int i=head[x]; i!=-1; i=e[i].next) {
        int y=e[i].to, w=e[i].w;
        
        if (!dfn[y]) { // y没有被访问过
            child++, fa[y]=x;
            dfs(y);
            low[x]=min(low[x], low[y]); // 尝试更新时间戳
            // 注意: 是判断 x 不是判断 y
            if (fa[x]==-1 && child>=2) { // 割点 case2
                cp.push_back(x);
            }
            if (fa[x]!=-1 && low[y]>=dfn[x]) { // case1
                cp.push_back(x);
            }
            if (low[y]>dfn[x]) { // 桥
                bg.push_back({x, y}); // 存桥的起点
            }
        }
            /*
             * 无向图中不需要处理父亲的边(搜索树中的父亲)
             */
        else if (fa[x]!=y) {
                low[x]=min(low[x], low[y]);
            }
        
    }
}
int main() {
   // 建图
   cin>>n>>m;
   memset(head, -1, sizeof(head));
   memset(fa, -1, sizeof(fa));
   int u, v, w, cnt=0;
   for (int i=1; i<=m; i++) {
       cin>>u>>v>>w;
       e[cnt]={v, w, head[u]};
       head[u]=cnt++;
       // 无向图
       e[cnt]={u, w, head[v]};
       head[v]=cnt++;
   }
   // DFS 每个点
   for (int i=1; i<=n; i++) {
       if (!dfn[i]) { // 如果i点没有被dfs过
           dfs(i);
       }
   }
    // 输出dfn和low
    for (int i=1; i <= n; i++) {
        cout <<i<<": "<<dfn[i]<< ", "<<low[i]<<endl;
    }
   cout<<"\n割点: ";
   for (int &it:cp) cout<<it<<" ";
   cout<<endl<<"桥: \n";
   for (auto &[f, s]:bg) cout<<f<<"->"<<s<<endl;
   cout<<endl;
    
    return 0;
}
/*
8 9
1 2 1
1 3 1
2 3 1
2 4 1
3 4 1
4 5 1
5 7 1
5 8 1
8 6 1
  
  输出:
1: 1, 1
2: 8, 1
3: 2, 1
4: 3, 1
5: 4, 4
6: 6, 6
7: 7, 7
8: 5, 5

割点: 8 5 5 4
桥:
8->6
5->8
5->7
4->5

 
 */

