//
// Created by hupax on 25-3-29.
//
#include <iostream>
#include <algorithm>
#define fo(a, b) for (int i=a; i<=b; i++)
using namespace std;
const int N=1e3+5;
struct P {
  int s, a, e;
  bool operator<(const P &b) const {
      return s+a+e == b.s+b.a+b.e ? s+a < b.s+b.a : s+a+e < b.s+b.a+b.e;
  }
} p[N];
int n;
long long ans=0, t;
int main() {
    cin >> n;
    fo(1, n) cin >> p[i].s >> p[i].a >> p[i].e;
    sort(p+1, p+n+1);
    fo(1, n) {
        t=t+p[i].s+p[i].a+p[i-1].e;
        ans+=t;
    }
//    ans-=p[n].e;
    cout << ans;
    
    return 0;
}

// 2 8 10