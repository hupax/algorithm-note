//
// Created by supanx on 25-3-22.
//
#include <iostream>
#include <cmath>
#include <algorithm>
#define fo(x, y) for (int i=x; i<=y; i++)
using namespace std;
void read(int &x) {
    x=0; char ch=getchar();
    while (isdigit(ch)) {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
}
const int maxn = 5e4+5;
const int maxm = 5e4+5;
const int maxa = 5e4+5;
int n, m, a[maxn], ans[maxm], bsiz, k;
int frq[maxa], res = 0, val;
struct Q {
  int l, r, i;
  bool operator<(const Q &b) const {
      if (l/bsiz != b.l/bsiz) return l < b.l;
      return ((l/bsiz)&1) ? r < b.r : r > b.r;
  }
} q[maxm];
void add(int pos) {
    val = a[pos];
    res -= frq[val]*frq[val];
    frq[val]++;
    res += frq[val]*frq[val];
}
void sub(int pos) {
    val = a[pos];
    res -= frq[val]*frq[val];
    frq[val]--;
    res += frq[val]*frq[val];
}
int main() {
    read(n), read(m), read(k);
    fo(1, n) read(a[i]);
    fo(1, m) {
        read(q[i].l), read(q[i].r);
        q[i].i=i;
    }
    bsiz = sqrt(n);
    sort(q+1, q+m+1);
    int l = 1, r = 0;
    fo(1, m) {
        while (q[i].l < l) add(--l);
        while (q[i].r > r) add(++r);
        while (q[i].l > l) sub(l++);
        while (q[i].r < r) sub(r--);
        ans[q[i].i] = res;
    }
    fo(1, m) cout << ans[i] << endl;
    return 0;
}