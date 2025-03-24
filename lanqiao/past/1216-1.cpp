//
// Created by 沙枭 on 2024/4/24.
//
#include <iostream>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

int link, m;
int a[105][105];
int step[105][105];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int stx, sty, endx, endy;

int bfs()
{
    queue<pair<int, int>> q;
    q.emplace(stx, sty);
    step[stx][sty] = 0;
    
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if (x == endx && y == endy)
            return step[x][y];
        for (int i = 0; i < 4; ++i)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx >= 1 && tx <= link && ty >= 1 && ty <= m && step[tx][ty] == 0 && a[tx][ty] == 1)
            {
                step[tx][ty] = step[x][y] + 1;
                q.emplace(tx, ty);
            }
        }
    }
    return -1;
}

int main()
{
    memset(step, 0, sizeof(step));
    cin >> link >> m;
    for (int i = 1; i <= link; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
        }
    }
    cin >> stx >> sty >> endx >> endy;
    for (int i = 1; i <= link; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cout << step[i][j] << " ";
        }
        cout << endl;
    }
    cout << bfs() << endl;
    
    return 0;
}
/*
5 5
1 0 1 1 0
1 1 0 1 1
0 1 0 1 1
1 1 1 1 1
1 0 0 0 1
1 1 5 5 */