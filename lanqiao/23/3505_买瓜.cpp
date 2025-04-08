//
// Created by hupax on 25-4-8.
//
#include <bits/stdc++.h>
using namespace std;
const int N=35;
const int M=1e9+5;
const double df=1e-6;
int n;
double m, a[N];
int ans=M;
void dfs(int i, double sum, int cnt) {
    if (abs(sum-m)<df) {
        ans=min(ans, cnt);
        return;
    }
    if (i==n+1 || sum>m+df || cnt>=ans) return;
    // 不选
    dfs(i+1, sum, cnt);
    // 选
    dfs(i+1, sum+a[i], cnt);
    // 选切一半
    dfs(i+1, sum+a[i]/2, cnt+1);
    
}
int main() {
    cin>>n>>m;
    for (int i=1; i<=n; i++) cin>>a[i];
    dfs(1, 0.0, 0);
    cout<<(ans==M?-1:ans);
    
    return 0;
}

