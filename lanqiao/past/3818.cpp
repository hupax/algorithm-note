//
// Created by supanx on 25-3-12.
//
#include <iostream>
using namespace std;
const int maxx = 1005;

int n, m, e;
char g[maxx][maxx];
int fg[maxx][maxx];
int x1, y1, x2, y2;
int x[4] = {1, 0, -1, 0};
int y[4] = {0, -1, 0, 1};
int q[maxx * maxx], f, r;
int bfs() {
    q[]
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
        cin >> g[i][j];
    cin >> e;
    g[x1][y1] = e;
    return 0;
}