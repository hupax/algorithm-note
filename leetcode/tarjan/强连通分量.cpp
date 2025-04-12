//
// Created by hupax on 25-4-12.
//
// 求一个有向图中的墙连通分量 即:
//  图中几个分量是可以从任一个点到其他任意一个点的

#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=1e3+5, M=2e4+5;

// 有向图, n个点m条边
int n, m;
// 星存图
struct E {
  int to, w, next;
} e[M];
int head[N];
int times=0, sta[N], p=0, flag[N]; // 时间戳 栈 是否在栈中
/*
 * // dfn: i : DFS中, x点被访问的时间点
 * // low: j : x通过边(或者有向边)可回溯到的最早的时间点
 */
int dfn[N], low[N];
vector<vector<int>> scc; // 强连通分量Strong connected components
void dfs(int x) { // x: 当前的点
    sta[p++]=x; // 先入栈
    flag[x]=1;
    dfn[x]=low[x]=++times;
    // 遍历x的邻接点
    for (int i=head[x]; i != -1; i=e[i].next) {
        int y=e[i].to, w=e[i].w;
        
        if (!dfn[y]) { // y没有被访问过
            dfs(y);
            low[x]=min(low[x], low[y]);
        }
        else if(flag[y]) { // 如果y在栈中,则有可能更新x
            low[x]=min(low[x], low[y]);
        }
    }
    // 当dfn[x] == low[x]时，说明x是一个强连通分量的根节点
    if (dfn[x]==low[x]) { // 出栈到遇到 x 出栈的就是一个分量
        vector<int> cc;
        while (sta[p-1]!=x) {
            cc.push_back(sta[p-1]);
            flag[sta[p-1]]=0;
            p--;
        }
        cc.push_back(sta[p-1]);
        flag[sta[p-1]]=0;
        p--;
        scc.push_back(cc);
    }
    
}
int main() {
    // 建图
    cin >> n >> m;
    memset(head, -1, sizeof(head));
    int u, v, w, cnt=0;
    for (int i=1; i <= m; i++) {
        cin >> u >> v >> w;
        e[cnt]={v, w, head[u]};
        head[u]=cnt++;
    }
    // DFS 每个点
    for (int i=1; i <= n; i++) {
        if (!dfn[i]) { // 如果i点没有被dfs过
            dfs(i);
        }
    }
    // 输出dfn和low
    for (int i=1; i <= n; i++) {
        cout << i << ": " << dfn[i] << ", " << low[i] << endl;
    }
    for (auto &its:scc) {
        for (auto &it:its) cout<<it<<" ";
        cout<<endl;
    }
    
    return 0;
}

/*
7 9
1 2 1
1 6 1
2 3 1
3 4 1
3 5 1
4 2 1
4 5 1
6 7 1
7 1 1

 */