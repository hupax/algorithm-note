//
// Created by hupax on 25-4-10.
//
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define inf INT_MAX
using namespace std;
const int N=1e5+5;
int n, k, vis[N], ans=0, cot=0;
void bfs(int st) {
    queue<int> q;
    q.push(st);
    while (!q.empty()) {
        cot++;
        int cur=q.front(); q.pop();
        if (!vis[cur]) ans++;
        vis[cur]=1;
        if (ans==n) return;
        
        int nex1=(cur+1)%n, nex2=(cur+k)%n;
        if (!vis[nex1]) q.push(nex1);
        if (!vis[nex2]) q.push(nex2);
    }
}
int main() {
    cin>>n>>k;
    bfs(0);
    cout<<cot;
    
    return 0;
}