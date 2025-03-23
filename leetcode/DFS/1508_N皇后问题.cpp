//
// Created by supanx on 25-3-18.
//
#include <iostream>
#include <bitset>
using namespace std;

int n, ans = 0;
bitset<15> col, dlg1, dlg2;
void dfs(int row, int cur) {
    if (row == n + 1) {
        if (cur == n + 1) ans++;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (col[i] || dlg1[row + i] || dlg2[row - i + n]) continue;
        col[i] = dlg1[row + i] = dlg2[row - i + n] = 1;
        dfs(row + 1, cur + 1);
        col[i] = dlg1[row + i] = dlg2[row - i + n] = 0;
    }
}
int main() {
    cin >> n;
    dfs(1, 1);
    cout << ans;
    return 0;
}