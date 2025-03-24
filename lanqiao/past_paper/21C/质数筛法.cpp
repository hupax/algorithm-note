//
// Created by supanx on 25-3-22.
//
#include <iostream>
using namespace std;
// 快速找出 1 ~ n 中的质数
int n, cnt=0, p[10005]; // cnt:质数的个数, p[i]=x : 1到n中第i个质数为 x
int isp[1000005]; // 值为0 i是质数 值为1 i不是质数
int main() {
    cin >> n;
    isp[1] = 1;
    for (int i=2; i<=n; i++) { // 枚举所有数+每个质数的倍数
        if (!isp[i]) {
            cnt++;
            p[cnt] = i;
        }
        // 把 i 当做质数的倍数来看, 枚举所有质数的i倍
        for (int j=1; j<=cnt; j++) {
            int x=i*p[j];
            if (x>n) break;
            isp[x]=1;
            if (i%p[j]==0) break;
        }
    }
    for (int i=1; i<=cnt; i++) {
        cout << p[i] << " ";
    }
    
    return 0;
}