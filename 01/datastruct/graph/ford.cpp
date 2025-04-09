//
// Created by hupax on 25-4-9.
//
#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
// 边级数组存图
struct E {
  int u, v, w;
} e[N*30];
int n, m;
int dis[N];

void ford() {
//    for (int i=1; i<=n; i++) dis[i]=0x3f;
    memset(dis, 0x3f, sizeof(dis));
    
    dis[1]=0; // 1是源点
    
    // n-1次松弛
    for (int i=1; i<n; i++) {
        for (int j=1; j<=m; j++) {
            int u=e[j].u, v=e[j].v, w=e[j].w;
            if (dis[u]!=0x3f && dis[v]>dis[u]+w) {
                dis[v]=dis[u]+w;
            }
        }
    }
    
    
}
int main() {
    cin>>n>>m;
    int u, v, w;
    for (int i=1; i<=m; i++) {
        cin>>u>>v>>w;
        e[i]={u, v, w};
    }
    ford();
    for (int i=1; i <= n; i++)
        cout << dis[i] << " ";
    cout << endl;
    
    return 0;
}