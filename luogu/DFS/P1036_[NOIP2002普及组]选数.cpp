//
// Created by supanx on 25-3-18.
//
#include <iostream>
#define fo(x, y) for (int i=x; i<=y; i++)
using namespace std;
void read(int &x) {
    x=0; int f=1; char ch=getchar();
    while (!isdigit(ch)) {
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (isdigit(ch)) {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
}
inline int isp(int &x) {
    if (x==1) return 0;
    if (x==2 || x ==3) return 1;
    if (x%6!=5 && x%6!=1) return 0;
    for (int i=5; i*i<=x; i+=6) {
        if (x%i==0 || x%(i+2)==0) return 0;
    }
    return 1;
}
const int maxn=25;
int n, a[maxn], k;
int ans=0;
void dfs(int cnt, int sum, int idx) {
    if (cnt == k) {
        if (isp(sum)) ans++;
        return;
    }
    fo(idx, n-k+cnt+1) dfs(cnt+1, sum+a[i], i+1);
}
int main() {
    read(n), read(k);
    fo(1, n) read(a[i]);
    dfs(0, 0, 1);
    cout << ans;
    return 0;
}