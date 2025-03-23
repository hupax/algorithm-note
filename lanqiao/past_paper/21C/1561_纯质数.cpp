//
// Created by supanx on 25-3-22.
//
#include <iostream>
using namespace std;
const int MAXN = 20210605+5;
int isp[MAXN], p[MAXN];
int cnt=0;
int main() {
    int n=20210605;
    isp[1]=1;
    for (int i=2; i<=n; i++) {
        if (!isp[i]) p[++cnt]=i;
        // 枚举质数的i倍
        for (int j=1; j<=cnt && i*p[j]<=n; j++) {
            isp[i*p[j]]=1;
            if (i%p[j]==0) break;
        }
    }
    
    int ans=0, f, k;
    for (int i=1; i<=n; i++) {
        if (isp[i]) continue;
        f=1, k=i;
        while (k) {
            int d=k%10;
            if (d!=2&&d!=3&&d!=5&&d!=7) {
                f=0;
                break;
            }
            k/=10;
        }
        if (f) ans++;
    }
    cout << ans;
    
    return 0;
}