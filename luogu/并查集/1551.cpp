//
// Created by supanx on 25-3-4.
//
//
#include <iostream>
using namespace std;

int n, m, p, f[5005];
int m1, m2;
int find_f(int x) {
    if (f[x] == x) {
        return x;
    }
    return f[x] = find_f(f[x]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    while (m--) {
        cin >> m1 >> m2;
        int fm1 = find_f(m1);
        int fm2 = find_f(m2);
        f[fm1] = fm2;
    }
    while (p--) {
        cin >> m1 >> m2;
        if (find_f(m1) == find_f(m2)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}
