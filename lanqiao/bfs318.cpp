//
// Created by 沙枭 on 2024/4/29.
//
// 寻找岛屿周长;
#include <iostream>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

const int M = 1005;
int n, m, a[M][M];
bool f[M][M];
int len = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
void bfs(int &xx, int &yy)
{
    queue<pair<int, int>> q;
    q.emplace(xx, yy);
    f[xx][yy] = 1;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        for (int i = 0; i < 4; ++i)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && !f[tx][ty] && a[tx][ty])
            {
                q.emplace(tx, ty);
                f[tx][ty] = 1;
            }
            else len++;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            if (a[i][j])
            {
                bfs(i, j);
                cout << len;
                return 0;
            }
  // 请在此输入您的代码
  return 0;
}