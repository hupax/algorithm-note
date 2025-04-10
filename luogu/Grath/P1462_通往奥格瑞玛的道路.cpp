//
// Created by hupax on 25-4-10.
// 二分 + dijkstra优化版
#include <bits/stdc++.h>
#define endl "\n"
#define pii pair<int, int>
using namespace std;
const int N=1e4+5, M=5e4+5, inf=1e9+5;
int n, m, b, c[N], head[N]; // a[i]为节点权值
int dis[N], vis[N];
struct E {
  int to, w, next;
} e[2*M];
int l=0, r=0; // 答案范围 [0, max(a[i])]
int check(int mid) {
    if (mid<c[1]) return 0; // 1为起点 出不了起点 ->剪枝
//    memset(dis, 1e9, sizeof(dis));
//    memset(vis, 0, sizeof(vis));
    for (int i=1; i <= n; i++) dis[i]=inf, vis[i]=0;
    priority_queue<pii, vector<pii>, greater<>> q;
    q.push({0, 1});
    dis[1]=0;
    
    while (q.size()) {
        auto [d, u]=q.top(); q.pop();
        if (vis[u]) continue;
        vis[u]=1;
        
        for (int i=head[u]; i!=-1; i=e[i].next) {
            int v=e[i].to, w=e[i].w;
            if (c[v]<=mid && dis[v]>dis[u]+w) {
                dis[v]=dis[u]+w;
                q.push({dis[v], v});
            }
        }
    }
    
    return dis[n]<=b;
}
int main() {
    cin>>n>>m>>b;
    for (int i=1; i<=n; i++) {
        cin>>c[i]; r=max(r, c[i]);
        head[i]=-1; l=min(l, c[i]);
    }
    int u, v, w, cnt=0;
    for (int i=1; i<=m; i++) {
        cin>>u>>v>>w;
        if (u==v) continue; // 排除自边
        e[cnt].to=v;
        e[cnt].w=w;
        e[cnt].next=head[u];
        head[u]=cnt++;
        e[cnt]={u, w, head[v]}; // 双向边
        head[v]=cnt++;
    }
    if (!check(r)) {
        cout<<"AFK"<<endl;
        return 0;
    }
    int ans, mid;
    while (l<=r) { // 二分答案
        mid=(l+r)>>1;
        if (check(mid)) { // 说明猜的答案大了
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans<<endl;
    
    return 0;
}