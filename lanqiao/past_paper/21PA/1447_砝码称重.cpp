//
// Created by hupax on 25-3-26.
//
#include <iostream>
#include <unordered_set>
#define fo(x, y) for (int i=x; i<=y; i++)
using namespace std;
const int N=105;
int n, a[N];
unordered_set<int> ans;
int main() {
    cin>>n;
    fo(1, n) cin>>a[i];
    // 求第 n 块砝码可以称多少种重量
    // 假设 n-1 个砝码可以称多少种重量已经知道 为 ans.size()
    // 第一块砝码 w1 可以称 0 和 w1 两种
    // 每加一块砝码wi有3种情况 1.+wi 2.-wi 3.0(不选)
    ans.insert(0);
    fo(1, n) {
        unordered_set<int> nxt; // 加下一块可以有多少种称法
        for(int s:ans) {
            nxt.insert(s+a[i]);
            nxt.insert(s-a[i]);
            nxt.insert(s);
        }
        ans=std::move(nxt);
    }
    // 处理负数
    int p=0;
    for(int s:ans) if (s<=0 && ans.count(-s)) p++;
    cout<<ans.size()-p;
    
    return 0;
}