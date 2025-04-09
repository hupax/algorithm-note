//
// Created by hupax on 25-4-9.
//
#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
struct E {
  int to, w, next;
} e[N*30];
int n, m, c[N], head[N];
int vis[N], dis[N];
void dijkstra(int st) {
    dis[st]=0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.push({0, st});
    
    while (!q.empty()) {
        auto [d, u]=q.top(); q.pop();
        if (vis[u]) continue;
        vis[u]=1;
        for (int i=head[u]; i; i=e[i].next) {
            int v=e[i].to, w=e[i].w;
            if (dis[v]>dis[u]+w+c[v]) {
                dis[v]=dis[u]+w+c[v];
                q.push({dis[v], v});
            }
        }
    }
}
int main() {
    cin>>n>>m;
    for (int i=1; i<=n; i++) cin>>c[i], dis[i]=N*N;
    int u, v, w, cnt=0;
    for (int i=1; i<=m; i++) {
        cin>>u>>v>>w;
        e[cnt]={v, w, head[u]};
        head[u]=cnt++;
        e[cnt]={u, w, head[v]};
        head[v]=cnt++;
    }
    dijkstra(1);
    cout<<dis[n]-c[n];
    
    
    return 0;
}

