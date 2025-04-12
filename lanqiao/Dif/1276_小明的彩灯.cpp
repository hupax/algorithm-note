//
// Created by hupax on 25-3-24.
//
#include <iostream>
#define fo(x, y) for (int i=x; i<=y; i++)
#define gc getchar_unlocked()
using namespace std;
using ll = long long;
//void read(ll &x) {
//    x=0; int f=1;
//    char ch=getchar();
//    while (!isdigit(ch)) {
//        if (ch=='-') f=-1;
//        ch=getchar();
//    }
//    while (isdigit(ch)) {
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    x*=f;
//}
void read(ll &x) {
    int f=1; char ch=gc;
    while (!isdigit(ch)) {
        if (ch=='-') f*=-1;
        ch=gc;
    }
    while (isdigit(ch)) {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=gc;
    }
    x*=f;
}
const int maxn=5e5+5;
ll n, q, x, l, r;
ll ans[maxn], dif[maxn];

int main() {
    read(n), read(q);
    fo(1, n) {
        read(ans[i]);
        dif[i]=ans[i]-ans[i-1];
    }
    fo(1, q) {
        read(l), read(r), read(x);
        dif[l]+=x;
        dif[r+1]-=x;
    }
    fo(1, n) {
        ans[i]=ans[i-1]+dif[i];
        cout << (ans[i]>0?ans[i]:0) << " ";
    }
    return 0;
}

