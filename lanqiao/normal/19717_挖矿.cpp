//
// Created by hupax on 25-4-9.
//
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n, m, a[N];
int main() {
    cin>>n>>m;
    for (int i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);
    int l=1, r=1;
    int ans=0;
    while (r<n) {
        int p=a[r]-a[l];
        if (p<=m) {
            ans=max(ans, r-l+1);
            r++;
        } else l++;
    }
    cout<<ans;
    
    return 0;
}