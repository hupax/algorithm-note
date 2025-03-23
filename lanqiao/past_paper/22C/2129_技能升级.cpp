//
// Created by supanx on 25-3-18.
//
#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
int64_t n, m, a, b, ans = 0;
struct sk {
  ll a, b, cnt;
  bool operator<(const sk &k) const {
      return a == k.a ? b < k.b : a < k.a;
  }
};
//auto cmp = [](sk &x, sk &y) {return }
priority_queue<sk> q;
int main() {
    scanf("%lld %lld", &n, &m);
    while (n--) {
        scanf("%lld %lld", &a, &b);
        q.push({a, b, a % b ? a/b+1:a/b});
    }
    while (!q.empty() && m--) {
        sk p = q.top();
        q.pop();
        ans += p.a;
        p.a -= p.b;
        p.cnt--;
        
        while (p.a >= q.top().a && p.a > 0 && p.cnt && m - 1 > 0) {
            ans += p.a;
            p.a -= p.b;
            p.cnt--;
            m--;
        }
        if (!p.cnt || p.a <= 0) continue;
        q.push(p);
    }
    cout << ans;
    
    return 0;
}
/*
3 3
10 5
9 2
8 1
 */