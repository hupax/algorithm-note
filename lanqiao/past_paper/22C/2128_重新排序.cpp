//
// Created by supanx on 25-3-18.
// // 差分
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
int n, m, A[maxn], l, r;
ll dif[maxn], ans = 0;
int main() {
    cin >> n;
    for (int i=1; i<=n; i++) scanf("%d", &A[i]);
    cin >> m;
    for (int i=1; i<=m; i++) {
        cin >> l >> r;
        dif[l]++;
        dif[r+1]--;
    }
//    for (int i = 0; i <= n + 2; i++) {
//        cout << dif[i] << " ";
//
//    }
    // 前缀和还原出 第 i 位出现的频率 并顺便算出原来的和
    for (int i=1; i<=n; i++) {
        dif[i] += dif[i-1];
        ans += A[i]*dif[i];
    }
    sort(dif+1, dif+n+1);
    sort(A+1, A+n+1);
    for (int i=1; i<=n; i++) {
        ans -= A[i]*dif[i];
    }
    cout << -ans;
    
    
    return 0;
}