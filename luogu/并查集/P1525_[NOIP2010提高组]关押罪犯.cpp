//
// Created by hupax on 25-3-26.
//
#include <iostream>
#include <algorithm>
#define fo(x, y) for (int i=x; i<=y; i++)
using namespace std;
inline void read(int &x) {
    x=0; int f=1; char ch=getchar();
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
const int N=2e4+5;
const int M=1e5+5;
struct P {
  int a, b, c;
  bool operator<(const P &p) const {
      return c>p.c;
  }
} p[M];
int n, m;
int fah[2*N]; // f[i+n] 表示 i 的敌人
inline int find(int x) {
    if (x==fah[x]) return x;
    return fah[x]=find(fah[x]);
}
int main() {
    read(n), read(m);
    fo(1, m) {
        read(p[i].a); read(p[i].b); read(p[i].c);
    } fo(1, n) {
        fah[i]=i; fah[i+n]=i+n; // 初始 i 的敌人为 i+n
    }
    sort(p+1, p+m+1);
    int fa, fb, fad, fbd;
    fo(1, m) {
        fa=find(p[i].a), fb=find(p[i].b);
        fad=find(p[i].a+n), fbd=find(p[i].b+n);
        if (fa==fb||fad==fbd) { // 说明属于同一个集合,分完了.之前分过了
            cout<<p[i].c;
            return 0;
        }
        // a和b 是敌人 合并 a和b的敌人fbd b和a的的人fad
        fah[fa]=fbd;
        fah[fb]=fad;
    }
    cout<<0;
    return 0;
}