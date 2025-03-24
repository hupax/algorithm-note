//
// Created by supanx on 25-3-7.
//
/* 合并果子 n - 1 次
 * 每次合并的重量最小 n - 1 次的最小
 *
 */
#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
ll n, k;
priority_queue<ll, vector<ll>, greater<ll>> q;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> k;
        q.push(k);
    }
    int ans, res = 0;
    while (q.size() > 1) {
        ans = 0;
        ans += q.top();
        q.pop();
        ans += q.top();
        q.pop();
        q.push(ans);
        res += ans;
    }
    cout << res;
    return 0;
}