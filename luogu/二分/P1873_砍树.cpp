//
// Created by hupax on 25-4-10.
//
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=1e6+5;
int n, a[N];
long long m;
// 二分答案
int check(int mid) {
    long long sum=0;
    for (int i=1; i<=n; i++) if (a[i]-mid>0) sum+=a[i]-mid;
    return sum>=m;
}
int main() {
    cin>>n>>m;
    int l=0, r=0;
    for (int i=1; i<=n; i++) cin>>a[i], r=max(r, a[i]);
    int mid, ans;
    while (l<=r) {
        mid=(l+r)>>1;
        if (check(mid)) {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans;
    
    return 0;
}