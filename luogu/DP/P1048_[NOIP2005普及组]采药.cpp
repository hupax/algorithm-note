//
// Created by supanx on 25-3-18.
//
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int tm, m;
int dp[1005], w[105], v[105];
int main() {
    cin >> tm >> m;
    for (int i = 1; i <= m; i++) cin >> w[i] >> v[i];
    for (int i = 1; i <= m; i++) {
        for (int j = tm; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[tm];
    stack<int> s;
    s.push(1);
    vector<int> v;
    v.clear();
    return 0;
}
/*
70 3
71 100
69 1
1 2
*/