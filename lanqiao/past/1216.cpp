//
// Created by 沙枭 on 2024/4/23.
//
// 1216 走迷宫
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int link, m, step[105][105];
int mm = 99999999;
int stx, sty, endx, endy;
int a[105][105];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
void dfs(int x, int y, int step)
{
    if (x == endx && y == endy)
    {
        if (mm > step)
            mm = step;
        return;
    }
    for (int i = 0; i <= 3; ++i)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx >= 1 && tx <= link && ty >= 1 && ty <= m && a[tx][ty] != 0 && step[tx][ty] != 1)
        {
            step[tx][ty] = 1;
            dfs(tx, ty, step + 1);
            step[tx][ty] = 0;
        }
    }
}
int main()
{
    cin >> link >> m;
    memset(step, 0, sizeof(step));
    for (int i = 1; i <= link; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    cin >> stx >> sty >> endx >> endy;
    step[stx][sty] = 1;
    dfs(stx, sty, 0);
    if (mm == 99999999)
        mm = -1;
    cout << mm << endl;
    // 请在此输入您的代码
    return 0;
}
