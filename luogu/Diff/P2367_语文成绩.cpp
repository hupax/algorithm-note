//
// Created by supanx on 25-3-22.
//
#include <iostream>
#include <climits>
#define fo(x, y) for (int i=x; i<=y; i++)
using namespace std;
void read(int &x) {
    x=0;int f=1;
    char ch=getchar();
    while (!isdigit(ch)) {
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (isdigit(ch)) {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    x*=f;
}
const int maxn=5e6+5;
int n, p, a[maxn], x, y, z, ans=INT_MAX;
int dif[maxn]; // 差分数组
int main() {
    read(n), read(p);
    fo(1, n) {
        read(a[i]);
        dif[i]=a[i]-a[i-1];
    }
    fo(1, p) {
        read(x), read(y), read(z);
        dif[x]+=z;
        dif[y+1]-=z;
    }
    fo(1, n) {
        a[i]=a[i-1]+dif[i];
        ans=min(ans, a[i]);
    }
    cout << ans;
    return 0;
}