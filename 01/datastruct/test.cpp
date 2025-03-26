//
// Created by supanx on 25-3-4.
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fo(i, a, b) for(int i=a;i<=b;i++)

const int N=2e5+5, MOD=1e9+7;
int fac[N], inv[N];

// 快速幂
int qmi(int a, int b) {
    int res=1;
    while (b) {
        if (b&1) res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}

// 预处理阶乘和逆元
void init() {
    fac[0]=inv[0]=1;
    fo(i, 1, N-1) {
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=qmi(fac[i], MOD-2); // 费马小定理逆元
    }
}

// 组合数 C(n, k)
int C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fac[n]*inv[k]%MOD*inv[n-k]%MOD;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    
    int n, m;
    cin >> n >> m;
    cout << C(n+m-2, m-1) << '\n';
}
