//
// Created by supanx on 25-3-5.
//

#include <iostream>
using namespace std;
const int maxs = 1e6 + 5;
int f[maxs];
int m, n, a, b, k;
int find_f(int x) {
    return f[x] == x ? x : f[x] = find_f(f[x]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    n *= m;
    for (int i = 1; i <= n; i++) f[i] = i;
    for (int i = 1; i <= k; i++) {
        cin >> a >> b;
        int fa = find_f(a);
        int fb = find_f(b);
        f[fb] = fa;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (f[i] == i) ans++;
    }
    cout << ans;
    return 0;
}
/*
5 4
16
2 3
1 5
5 9
4 8
7 8
9 10
10 11
11 12
10 14
12 16
14 18
17 18
15 19
19 20
9 13
13 17
*/