//
// Created by supanx on 25-3-18.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;
ll n, m, a, b, ans = 0;
vector<ll> res;
int main() {
    scanf("%lld %lld", &n, &m);
    while (n--) {
        scanf("%lld %lld", &a, &b);
        ll cnt = min(a%b?a/b+1:a/b, m);
        for (ll i = 0; i < cnt; i++) {
            ll val = a - b * i;
            if (val <= 0) break;
            res.push_back(val);
        }
    }
    ll p = min((ll)res.size(), m);
    nth_element(res.begin(), res.begin() + p, res.end(), greater<>());
    sort(res.begin(), res.begin() + p, greater<>());
//    for (auto &it:res) cout << it << " ";
    for (ll i = 0; i < p; i++) ans += res[i];
    cout << ans;
    
    return 0;
}
/*
3 3
10 5
9 2
8 1
 */