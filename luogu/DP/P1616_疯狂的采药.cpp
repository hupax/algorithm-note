//
// Created by supanx on 25-3-23.
//
#include <iostream>
#define fo(x, y) for (int i=x; i<=y; i++)
using namespace std;
using ll=long long;
void read(ll &x) {
    x=0; char ch=getchar();
    while (isdigit(ch)) {
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
}
const int maxt=1e7+5;
const int maxm=1e4+5;
ll t, m, dp[maxt], w[maxm], v[maxm];

int main() {
    read(t), read(m);
    fo(1, m) read(w[i]), read(v[i]);
    fo(1, m) for (int j=w[i]; j<=t; j++) {
        dp[j]=max(dp[j], dp[j-w[i]]+v[i]);
    }
    cout << dp[t];
    return 0;
}