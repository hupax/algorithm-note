//
// Created by hupax on 25-3-25.
// 求 [L, R] 之间 0~9 出现的个数 R<=1e9
#include <iostream>
using namespace std;

const int N=20; // 不超过20位
int a[N];
// 求 n 的 [l, r] 之间的数 23456
// 23456
// k...1
int get(int l, int r) {
    int ans=0;
    for (int i=l; i>=r; i--) ans+=ans*10+a[i];
    return ans;
}
// 求10的次方
int p(int n) {
    int ans=1;
    while (n--) ans*=10;
    return ans;
}
// 求 0~n 中 x 出现的次数
int dp(int n, int x) {
//    if (!n) return 0; 1 <= L
    int k=0; // 数组 a 长度
    while (n) {
        a[++k]=n%10;
        n/=10;
    }
    int ans=0;
    // 计算 x 在每一位上的可能
    // 如果 x=0 则最高位不能是 0 , 如 n=23, x=0 中不能取 00 01 02...,
    // 如果存在前导0, 那么0就可以出现无限次. 所以 x= 0 循环从最高位下一位开始
    for (int i=k-!x; i>=1; i--) {
        // x 在第 4 位为例, n为6位数
        // 情况1: 左边要有数字
        // 前面取 [0, x1x2x3-1] 即取不到极限, (那么当前位随便取也不会超过 n ) 则后面两位可以任意取 0~99
        // 那么就有 x1x2x3 * 100 种.
        // 特殊: x=0 那么前3为不能取 0 只能取 [1, x1x2x3-1]之间的数
        if (i!=k) ans+=(get(k, i+1)-!x) * p(i-1);
        // 情况2: 左边取到极限, 即 x1x2x3 前面只有一种可能
        // A: x<a[i] 那么后面两位任然任意取 0~99
        // B: x==a[i] 那么后面两位最多取x5x6+1 (因为可以取 0~x5x6)
        if (x<a[i]) ans+=p(i-1);
        else if (x==a[i]) ans+=get(i-1, 1)+1;
    }
    
    return ans;
}
int l, r;
int main() {
    cin>>l>>r;
    for(int i=0; i<=9; i++) {
        cout<<dp(r, i) - dp(l-1, i)<<" "; // 前缀和
    }
    
    return 0;
}
