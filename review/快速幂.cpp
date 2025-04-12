//
// Created by hupax on 25-4-11.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll a=6, n=3, res=1;
    while (n) {
        if (n&1) res*=a;
        n>>=1;
        a*=a;
    }
    cout<<res;
    
    return 0;
}