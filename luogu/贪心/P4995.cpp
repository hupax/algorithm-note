//
// Created by supanx on 25-3-11.
//
#include <iostream>
#include <algorithm>
using namespace std;
const int maxx = 305;
int n;
long long ans = 0;
int h[maxx];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    h[0] = 0;
    sort(h, h + n + 1);
    int l = 0, r = n;
    while (l < r) {
        ans += (h[r] - h[l]) * (h[r] - h[l]);
        l++;
        ans += (h[r] - h[l]) * (h[r] - h[l]);
        r--;
    }
    
    cout << ans;
    
    return 0;
}