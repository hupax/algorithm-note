//
// Created by supanx on 25-3-20.
// 莫队算法
#include <iostream>
#include <cmath>
#include <algorithm>
const int maxn = 1e6 + 5;
const int maxm = maxn;
const int maxi = maxn;
int a[maxn];
int pos[maxn];
int ans[maxm];
int bck;
//int cnt[]
struct Q {
  int l, r, k; // [l, r] --> k
  bool operator<(const Q &b) const { // 奇偶排序优化
      if (l / bck != b.l / bck) return l < b.l;
      return (l / bck &  1) ? r < b.r : r > b.r;
  }
} q[maxn];
int main() {
    int n,m;
    std::cin>>n;
    // 分块
    bck = sqrt(n);
    for (int i=1; i<=n; i++) {
        std::cin>>a[i];
        // 所属的块
        pos[i]=i/bck;
    }
    std::cin>>m;
    for (int i=1; i<=m; i++) {
        std::cin>>q[i].l>>q[i].r;
        q[i].k=i;
    }
//    std::sort(q, q+m, [](Q &x, Q&y) { // 朴素排序,端点跳跃频繁,使用奇偶排序优化
//        return x.l == y.l ? x.r < y.r : x.l < y.l;
//    });
    int l=1, r=0, sum=0, cot=1;
//    for (int i=0; i<m; i++) {
//        while(q[i].l < l) Add(--l);
//        while(q[i].r > r) Add(++r);
//        while(q[i].l > l) Sub(l--);
//        while(q[i].r < r) Sub(r--);
//        ans[q[i].k]=sum;
//    }
    for (int i = 1; i <= m; i++) {
        while (q[i].l < l) sum += a[--l];
        while (q[i].r > r) sum += a[++r];
        while (q[i].l > l) sum -= a[l++];
        while (q[i].r < r) sum -= a[r--];
        ans[q[i].k] = sum;
    }
    for (int i=1; i<=m; i++) std::cout << ans[i] << " ";
    return 0;
}

/*
输入样例
6
1 2 3 4 3 2
3
1 2
3 5
2 6

*/