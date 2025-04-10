//
// Created by hupax on 25-4-10.
//
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=5e+5;
int s, n, m, mid;
int a[N], ans;
int check(int p) {
    int cur=0, nex=1;
    int sum=0;
    while (nex<=n+1) {
        if (a[nex]-a[cur]<p) sum++;
        else cur=nex;
        nex++;
    }
    return sum<=m;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin>>s>>n>>m;
    for (int i=1; i<=n; i++) cin>>a[i];
    a[n+1]=s;
    int l=1, r=s; // 答案范围 [1, s]
    while (l<=r) {
        mid=(l+r)>>1;
        if (check(mid)) {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans<<endl;
    
    return 0;
}