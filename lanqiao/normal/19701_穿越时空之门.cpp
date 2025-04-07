//
// Created by hupax on 25-4-6.
//
#include <bits/stdc++.h>
using namespace std;
int ans=0, a, b;
inline int check(int x) { // 返回4进制数位和
    int p=0;
    while (x) {
        p+=x%4;
        x/=4;
    }
    return p;
}
int main() {
    for (int i=1; i<=2024; i++) {
        bitset<20> bit(i);
        a=bit.count(), b=check(i);
        if (a==b) ans++;
    }
    cout<<ans;
    
    return 0;
}