//
// Created by hupax on 25-4-9.
//
#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
struct E {
  int to, w, next;
} e[N];
int n, m, dis[N], head[N], vis[N];
int usi[N]; // 记录松弛次数, 超过 n 即为存在负环
int spfa(int st) {
    memset(dis, 0x3f, sizeof(dis));
    queue<int> q;
    q.push(st);
    dis[st]=0;
    
    while (q.size()) {
        int u=q.front();
        q.pop();
        vis[u]=0; // 标记在上一轮中有没有被松弛
        usi[u]++;
        if (usi[u]>=n) return 0;
        for (int i=head[u]; i!=-1; i=e[i].next) {
            int v=e[i].to, w=e[i].w;
            if (!vis[v] && dis[v]>dis[u]+w) {
                dis[v]=dis[u]+w;
                vis[v]=1;
                q.push(v);
            }
        }
    }
    return 1;
}
int main() {
    cin>>n>>m;
    memset(head, -1, sizeof(head));
    int u, v, w, cnt=0;
    for (int i=1; i<=m; i++) {
        cin>>u>>v>>w;
        e[cnt].to=v;
        e[cnt].w=w;
        e[cnt].next=head[u];
        head[u]=cnt++;
    }
    spfa(1);
    
    for (int i=1; i <= n; i++)
        cout << dis[i] << " ";
    cout << endl;
    
    return 0;
}
