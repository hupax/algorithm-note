#include<iostream>
#include<queue>
#include<vector>
#include <cstring>
//#include <bits/stdc++.h>
#define fo(a, b) for (int i=a; i<=b; i++)
// using namespace std;
const int N=105;
// 拓扑排序
// 有向图，可能存在环  时间复杂度 O(n+m)
int n, m; // 点 1~n
struct  E {
    int to, w, next;
} e[10005];
int head[N], ind[N], cnt, topo[N], k;

// BFS 卡恩算法
int kahn() {
    std::queue<int> q;
    for(int i=1; i<=n; i++) if (ind[i]==0) q.push(i);
    int u, v;
    while (!q.empty()) {
        u=q.front(); q.pop();
        topo[++k]=u;
        for (int i=head[u]; ~i; i=e[i].next) {
            v=e[i].to;
            if (--ind[v]==0) q.push(v);
        }
    }
    return k==n; // 1 为无环
}

// DFS
std::vector<int> sta;
/*
    vis[i]=0  没有访问过
           1
           2  这个点走过一次了 现在正在遍历改点后面的点 --> 第一次走到改点时标记为 2
*/
int vis[N];
int flag=0; // 有无环
int ans;
void dfs(int u) {
    vis[u]=2; // 第一次访问
    // int v;
    for (int i=head[u]; ~i; i=e[i].next) {
        if (vis[e[i].to]==2) {
            ans=e[i].to; flag=1; return; // 有环 从ans开始
        }
        if (vis[e[i].to]) continue;
        dfs(e[i].to);
        if (flag==1) return; // y 后面后面有环  *********
    }
    sta.push_back(u);
    vis[u]=1;  // u 及其后面的点访问结束
}
int main() {
    std::cin>>n>>m;
    memset(head, -1, sizeof(head));
    int u, v;
    fo(1, m) {
        cin>>u>>v;
        e[cnt].to=v;
        e[cnt].next=head[u];
        head[u]=cnt++;
        ind[v]++;
    }


   // BFS版
    if (kahn()) fo(1, n) cout<<topo[i]<<" ";
    else std::cout<<"cir";


    // DFS
     while (sta.size()) {
        std::cout<<sta.back()<<" ";
        sta.pop_back();
     }
    return 0;


}
/*
5 6
1 2
2 4
3 2
3 4
4 5
5 2
*/
/*
5 5
1 2
2 4
3 2
3 4
4 5









*/
