//
// Created by hupax on 25-3-24.
//
// 完全背包
#include <iostream>
#define fo(x, y) for (int i=x; i<=y; i++)
using namespace std;
const int maxn=1e3+5;
int n, v;
int wi[maxn], vi[maxn], dp[maxn];
int main() {
    cin>>n>>v;
    fo(1, n) scanf("%d %d", &wi[i], &vi[i]);
    fo(1, n) for (int j=wi[i]; j<=v; j++) dp[j]=max(dp[j], dp[j-wi[i]]+vi[i]);
    cout<<dp[v];
    
    return 0;
}