//
// Created by supanx on 25-3-4.
//
#include <iostream>
using namespace std;
using ll = long long;
ll a, b, p, a1, b1, p1;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> a >> b >> p;
    a1 = a, b1 = b, p1 = p;
    ll ans = 1;
    while (b) {
        if (b % 2) ans = (ans * a) % p;
        b >>= 1;
        a = (a * a) % p;
    }
    printf("%lld^%lld mod %lld=%lld", a1, b1, p1, ans);
}