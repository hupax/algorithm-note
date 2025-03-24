//
// Created by supanx on 25-3-18.
//
#include <iostream>
#include <algorithm>
#include <valarray>
using namespace std;
using ll = long long;
const int maxn = 1e5+5;
const int maxm = 1e5+5;

int n, m, x;
int A[maxn];
int ans[maxn];
int bck; // 分块大小
ll f[(1 << 20)+5]; // 大小为Ai大小
struct Q {
  int l, r, k;
  bool operator<(const Q &b) const {
      if (l/bck != b.l/bck) return l < b.l;
      return ((l/bck)&1) ? r < b.r : r > b.r;
  }
} q[maxm];
// a ^ b = x; --> x ^ a = b;
int val, cnt = 0; // 当前位置的元素 满足条件的对数
void add(int pos) {
    val = A[pos];
    cnt += f[val^x];
    f[val]++;
}
void del(int pos) {
    val = A[pos];
    f[val]--;
    cnt -= f[val^x];
}
int main() {
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &q[i].l, &q[i].r);
        q[i].k = i;
    }
    bck = sqrt(n);
    sort(q+1, q+m+1);
    int l = 1, r = 0, res = 0; // 左右 个数
    for (int i = 1; i <= m; i++) {
        while (q[i].l > l) del(l++); // l往右移
        while (q[i].r < r) del(r--); // r往左移
        while (q[i].l < l) add(--l); // l左移
        while (q[i].r > r) add(++r); // r往右移
        ans[q[i].k] = cnt > 0;
    }
    for (int i=1; i<=m; i++) cout << (ans[i]?"yes":"no") << endl;
    return 0;
}