//
// Created by 沙枭 on 2024/4/23.
//
#include <iostream>
#include <queue>

using namespace std;

struct edge
{
    int x;
    int y;
};

queue<edge> q;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int link, m, step[1001][1001], ans;
char c[1001][1001];

void bfs(int x, int y)
{
    q.push({x, y});
    c[x][y] = '0';
    while (!q.empty())
    {
        edge t = q.front();
        q.pop();
        for (int i = 0; i <= 3; ++i)
        {
            int xx = t.x + dx[i];
            int yy = t.y + dy[i];

            if (x >= 1 && x <= link && y >= 1 && y <= m && c[xx][yy] != '0')
            {
                q.push({xx, yy});
                c[xx][yy] = '0';
            }
        }
    }
}
int main()
{
    cin >> link >> m;
    for (int i = 1; i <= link; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> c[i][j];
    for (int i = 1; i <= link; ++i)
        for (int j = 1; j <= m; ++j)
            if (c[i][j] != '0')
            {
                ans++;
                bfs(i, j);
            }
    cout << ans << endl;
    return 0;
}