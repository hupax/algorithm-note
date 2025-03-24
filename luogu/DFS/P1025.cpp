//
// Created by supanx on 25-3-17.
//
/*剪枝, 重复性*/
#include <iostream>
using namespace std;
int n, k, ans = 0;
void dfs(int sum, int pre, int cnt) {
    if (cnt == k) {
        if (sum == n) ans++;
        return;
    }
    for (int i = pre; i <= (n - sum) / (k - cnt); i++) {
        dfs(sum + i, i, cnt + 1);
    }
}
int main() {
    cin >> n >> k;
    dfs(0, 1, 0);
    cout << ans;
    return 0;
}