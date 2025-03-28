//
// Created by hupax on 25-3-28.
//
#include <bits/stdc++.h>
#define fo(a, b) for (int i=a; i<=b; i++)
using namespace std;
const int N=205;
int n, a, b, m[N];
int dp[N];
int dfs(int p) {
    if (p==b) return 0;
    if (dp[p]!=-1) return dp[p];
    int res=INT_MAX;
    if (p-m[p]>0) {
        if (m[p]&&p-m[p]==b) res=min(res, dfs(p-m[p])+1);
    }
    if (p+m[p]<=n&&(m[p]||p+m[p]==b)) res=min(res, dfs(p+m[p])+1);
    return dp[p]=res;
}
int main() {
    cin>>n>>a>>b;
    fo(1, n) cin>>m[i], dp[i]=-1;
    cout<<dfs(a);
    
    return 0;
}
