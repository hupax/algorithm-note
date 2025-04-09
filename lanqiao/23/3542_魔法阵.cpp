//
// Created by hupax on 25-4-8.
//
#include <bits/stdc++.h>
#define fo(a, b) for (int i=a; i<=b; i++)
using namespace std;
const int N=1e3+5;
const int inf=1e7;
struct E {
  int to, w, next;
} e[N];
int head[N]; // head[i]=x 点i的第一条出边为x
int n, m, k, cnt=1;
int vis[N], dis[N];
void dijkstra(int s) {
    for (int i=0; i<n; i++) dis[i]=inf;
    dis[s]=0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.push({0, s});w
    while (!q.empty()) {
        auto [d, u]=q.top(); q.pop();
        if (vis[u]) continue;
        vis[u]=1;
        
        for (int i=head[u]; i; i=e[i].next) {
            int v=e[i].to, w=e[i].w;
            if (dis[v]>dis[u]+w) {
                dis[v]=dis[u]+w;
                q.push({dis[v], v});
            }
        }
        
    }
}
int main() {
    cin>>n>>k>>m;
    int u, v, w;
    fo(1, m) {
        cin>>u>>v>>w;
        e[cnt]={v, w, head[u]};
        head[u]=cnt++;
        e[cnt]={u, w, head[v]};
        head[v]=cnt++;
    }
    dijkstra(0);
    cout<<dis[7];
    
    return 0;
}

/*
9 8 16
0 1 1
0 2 5
1 2 3
1 3 7
1 4 5
2 4 1
2 5 7
3 4 2
3 6 3
4 5 3
4 6 6
4 7 9
5 7 5
6 7 2
6 8 7
7 8 4
 */