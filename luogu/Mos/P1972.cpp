//
// Created by supanx on 25-3-22.
//
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=1e6+5;
const int maxm=1e6+5;
const int maxa=1e6+5;
int n, m, a[maxn], ans[maxm], bsiz;
int frq[maxa], cnt=0, val;
struct Q {
  int l, r, i;
  bool operator<(const Q &b) const {
      if (l/bsiz!=b.l/bsiz) return l<b.l;
      return ((l/bsiz)&1)?r<b.r:r>b.r;
  }
} q[maxm];
void add(int pos) {
    val = a[pos];
    if (!frq[val]) cnt++;
    frq[val]++;
}
void sub(int pos) {
    val = a[pos];
    frq[val]--;
    if (!frq[val]) cnt--;
}
int main() {
    cin >> n;
    for (int i=1; i<=n; i++) scanf("%d", &a[i]);
    cin >> m;
    for (int i=1; i<=m; i++) {
        scanf("%d %d", &q[i].l, &q[i].r);
        q[i].i = i;
    }
    bsiz=sqrt(n);
    sort(q+1, q+m+1);
    int l=1, r=0;
    for (int i=1; i<=m; i++) {
        while (q[i].l < l) add(--l);
        while (q[i].r > r) add(++r);
        while (q[i].l > l) sub(l++);
        while (q[i].r < r) sub(r--);
        ans[q[i].i] = cnt;
    }
    for (int i=1; i<=m; i++) cout << ans[i] << endl;
    return 0;
}