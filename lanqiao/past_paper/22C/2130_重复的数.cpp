//
// Created by supanx on 25-3-18.
//
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
const int maxm=1e5+5;
const int maxa=1e5+5;               // 频率     该频率的个数
int n, m, A[maxn], ans[maxm], bsiz, frq[maxa], res[maxn];
struct Q {
  int l, r, k, id;
  bool operator<(const Q &b) const {
      if (l/bsiz != b.l/bsiz) return l < b.l;
      return ((l/bsiz)&1) ? r<b.r : r>b.r;
  }
} q[maxm];
int val;
void add(int pos) {
    val = A[pos];
    res[frq[val]]--; // 就的频率
    frq[val]++;
    res[frq[val]]++; // 新的频率
}
void sub(int pos) {
    val = A[pos];
    res[frq[val]]--;
    frq[val]--;
    res[frq[val]]++;
}
int main() {
    cin >> n;
    for (int i=1; i<=n; i++) scanf("%d", &A[i]);
    cin >> m;
    for (int i=1; i<=m; i++) {
        scanf("%d %d %d", &q[i].l, &q[i].r, &q[i].k);
        q[i].id = i;
    }
    bsiz = sqrt(n);
    sort(q+1, q+m+1);
    
    int l=1, r=0;
    for (int i=1; i<=m; i++) {
        while (q[i].l < l) add(--l);
        while (q[i].r > r) add(++r);
        while (q[i].l > l) sub(l++);
        while (q[i].r < r) sub(r--);
        ans[q[i].id] = res[q[i].k];
    }
    for (int i=1; i<=m; i++) cout << ans[i] << endl;
    return 0;
}