//
// Created by supanx on 25-3-15.
//
// 跳马
#include <iostream>
#include <queue>
using namespace std;
const int maxx = 405;
int n, m, x, y, ans[maxx][maxx], f[maxx][maxx];
queue<pair<int, int>> q;
int xx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int yy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
void bfs() {
    ans[x][y] = 0;
    f[x][y] = 1;
    q.push({x, y});
    while (!q.empty()) {
        // 出队
        auto fi = q.front();
        q.pop();
        // 入队
        for (int i = 0; i < 8; i++) {
            int xi = fi.first+xx[i], yi = fi.second+yy[i];
            if (!f[xi][yi] && xi > 0 && xi <= n && yi > 0 && yi <= m) {
                q.push({xi, yi});
                f[xi][yi] = 1;
                ans[xi][yi] += ans[fi.first][fi.second]+1;
            }
        }
    }
}
int main() {
    cin >> n >> m >> x >> y;
    bfs();
//    for (auto &i : ans) {
//        for (auto &j : i) cout << j << " ";
//        cout << endl;
//    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!ans[i][j] && !f[i][j]) printf("%-5d", -1);
            else printf("%-5d", ans[i][j]);
        }
        cout << endl;
    }
    return 0;
}