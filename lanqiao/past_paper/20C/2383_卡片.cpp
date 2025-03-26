//
// Created by hupax on 25-3-25.
// 给定组合的长度，和组合的个数，求最少有多少个元素
#include <iostream>
using namespace std;
using ll=long long;
ll comb(int n, int k) {
    ll res=1;
    for (int i=1; i<=k; i++) {
        res*=n-i+1;
        res/=i;
    }
    return res;
}
int n; //组合的个数, 长度为2
int ans=1; // 最少的元素个数
int main() {
    cin>>n;
    // 从ans中选出两个元素, 元素可以相同, 求最少n种选法
    /*
      公式 C(ans+2-1, 2) >= n;
     */
    while (comb(ans+2-1, 2) < n) ans++;
    cout<<ans;
    
    return 0;
}