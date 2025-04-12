//
// Created by hupax on 25-4-10.
//
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define inf INT_MAX
using namespace std;
const int N=1e5+5;
int n, k, vis[N], ans=0, cot=0, dis[N];
void bfs(int st) {
    queue<int> q;
    q.push(st);
    dis[st]=0;
    while (!q.empty()) {
        int cur=q.front(); q.pop();
        ans=max(ans, dis[cur]);
//        if (vis[cur]) continue;
//        else cot++;
//        if (cot==n) return;
//        vis[cur]=1;
        
        int nex1=(cur+1)%n, nex2=(cur+k)%n;
        if (!vis[nex1]) {
            q.push(nex1);
            dis[nex1]=dis[cur]+1;
            vis[nex1]=1;
//            ans=max(ans, dis[nex1]);
        }
        if (!vis[nex2]) {
            q.push(nex2);
            dis[nex2]=dis[cur]+1;
            vis[nex2]=1;
//            ans=max(ans, dis[nex2]);
        }
    }
}
int main() {
    cin>>n>>k;
    bfs(0);
    cout<<ans;
    
    return 0;
}