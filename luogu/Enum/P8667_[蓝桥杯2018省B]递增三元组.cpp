//
// Created by supanx on 25-3-22.
//
#include <iostream>
#include <algorithm>
#define fo(x, y)  for (int i=x; i<=y; i++)
using namespace std;
using ll = long long;
int read() {
    int x=0, f=1;
    char ch=getchar();
    while (!isdigit(ch)) {
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (isdigit(ch)) {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
const int maxn=1e5+5;
int n, A[maxn], B[maxn], C[maxn];
ll ans=0;
int main() {
    n=read();
    fo(1, n) A[i]=read(); fo(1, n) B[i]=read(); fo(1, n) C[i]=read();
    sort(A+1, A+n+1);sort(B+1, B+n+1);sort(C+1, C+n+1);
    fo(1, n) {
        ll n1=lower_bound(A+1, A+n+1, B[i])-A-1;
        ll n2=upper_bound(C+1, C+n+1, B[i])-C-1;
        ans+=n1*(n-n2);
    }
    cout << ans;
    return 0;
}