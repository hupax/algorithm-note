//
// Created by 沙枭 on 24-5-7.
//
// L3-037 夺宝大赛
#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <map>
using namespace std;
int m, link, x, vis[105][105], a[105][105];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int x, y, stx, sty;
map<pair<int, int>, int> f;
unordered_map<int, int> af;
map<pair<int, int>, int> uf;
void bfs()
{
    queue<pair<int, int>> q;
    q.emplace(x, y);
    vis[x][y] = 1;
    while (!q.empty())
    {
        int tx = q.front().first;
        int ty = q.front().second;
        q.pop();
        if (f.count({tx, ty}))
        {
            f[{tx, ty}] = vis[tx][ty] - 1;
            af[vis[tx][ty] - 1]++;
        }
        for (int i = 0; i < 4; ++i)
        {
            int vx = tx + dx[i];
            int vy = ty + dy[i];
            if (vx >= 1 && vx <= m && vy >= 1 && vy <= link && vis[vx][vy] == 0 && a[vx][vy])
            {
                vis[vx][vy] = vis[tx][ty] + 1;
                q.emplace(vx, vy);
            }
        }
    }
}
int main()
{
    cin >> m >> link;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= link; ++j)
        {
            cin >> a[i][j];
            if (a[i][j] == 2)
            {
                x = i;
                y = j;
            }
        }
    }
//    cout << x << " " << y << endl;
    cin >> x;
    for (int i = 1; i <= x; ++i)
    {
        cin >> stx >> sty;
        f[{sty, stx}] = 0;
        uf[{sty, stx}] = i;
//        speed[{y, x}] = 0;
    }
    bfs();
    vector<pair<pair<int, int>, int>> vec(f.begin(), f.end());
    sort(vec.begin(), vec.end(), [](pair<pair<int, int>, int> &xx, pair<pair<int, int>, int> &yy)
    {
      return xx.second < yy.second;
    });
//    for (auto &[key, v] : af)
//    {
//        cout << key << " " << v << endl;
//    }
    for (auto &[key, v] : vec)
    {
        if (af[v] == 1)
        {
            cout << uf[{key.first, key.second}] << " " << v << endl;
            return 0;
        }
    }
    cout << "No winner." << endl;
//    for (auto &[key, v] : f)
//        cout << key.first << " " << key.second << " " << v << endl;
    
    
    
    return 0;
}
/*
5 7
1 1 1 1 1 0 1
1 1 1 1 1 0 0
1 1 0 2 1 1 1
1 1 0 0 1 1 1
1 1 1 1 1 1 1
7
1 5
7 1
1 1
5 5
3 1
3 5
1 4
 
 
 */
