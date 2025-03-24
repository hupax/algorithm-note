//
// Created by supanx on 25-3-18.
//
#include <iostream>
using namespace std;

int n, m, t, xi, yi, sx, sy, ex, ey;
int map[10][10];
int f[10][10];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int ans = 0;
void dfs(int x, int y) {
    if (x == ex && y == ey) {
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if (nx <= 0 || nx > n || ny <= 0 || ny > n || f[nx][ny] || map[nx][ny]) continue;
        f[nx][ny] = 1;
        dfs(nx, ny);
        f[nx][ny] = 0;
    }
}
int main() {
    cin >> n >> m >> t;
    cin >> sx >> sy >> ex >> ey;
    while (t--) {
        cin >> xi >> yi;
        map[xi][yi] = 1;
    }
    f[sx][sy] = 1;
    dfs(sx, sy);
    cout << ans;
    return 0;
}