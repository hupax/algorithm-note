//
// Created by supanx on 25-3-4.
//
#include <iostream>
using namespace std;
const int maxs = 1e6 + 5;
int f[maxs];
int n, a, q, l, r;
int find_f(int x) {
    return f[x] == x ? x : f[x] = find_f(f[x]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) f[i] = i;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a) f[i] = find_f(a);
    }
    
    while (q--) {
        cin >> l >> r;
        while (l < r) {
            if (f[l] == f[r]) continue;
            int fl = find_f(l);
            int fr = find_f(r);
            f[fl] = fr;
            l++, r--;
        }
        for (int i = 1; i <= n; i++) cout << f[i] << " ";
        cout << endl;
    }
//    int ans = 0;
//    while (n--) {
//        if (f[n] != n) ans++;
//    }
//    cout << ans << endl;
    return 0;
}