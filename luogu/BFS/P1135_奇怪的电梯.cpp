//
// Created by hupax on 25-3-28.
//
#include <bits/stdc++.h>
#define fo(a, b) for (int i=a; i<=b; i++)
using namespace std;
const int N=205;
int n, a, b, m[N];
int dp[N]; // dp[i]=x 从 a 到 i 的最少次数为 x
queue<int> q;
int main() {
    cin>>n>>a>>b;
    fo(1, n) cin>>m[i], dp[i]=-1;
    q.push(a);
    dp[a]=0;
    while (!q.empty()) {
        int u=q.front(); q.pop();
        // 下一点: u-m[u] 存在,并且还未到达过
        if (u-m[u]>0 && dp[u-m[u]]==-1) {
            dp[u-m[u]]=dp[u]+1; // 下一点的次数是上一点的加一
            q.push(u-m[u]);
        }
        if (u+m[u]<=n && dp[u+m[u]]==-1) {
            dp[u+m[u]]=dp[u]+1;
            q.push(u+m[u]);
        }
    }
    cout<<dp[b];
    
    return 0;
}
