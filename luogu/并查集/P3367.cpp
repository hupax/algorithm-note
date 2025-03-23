//
// Created by supanx on 25-3-4.
//
#include <iostream>
using namespace std;
const int maxs = 1e6 + 5;
int n, m, z, x, y, f[maxs];
int find_f(int k) {
    return f[k] == k ? k : f[k] = find_f(f[k]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) f[i] = i;
    while (m--) {
        cin >> z >> x >> y;
        int fx = find_f(x);
        int fy = find_f(y);
        if (z == 2) fx == fy ? cout << "Y" << endl : cout << "N" << endl;
        else f[fx] = fy;
    }
    return 0;
}
