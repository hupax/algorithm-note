//
// Created by 沙枭 on 2024/4/23.
//
#include <iostream>

using namespace std;

int link, m, ans;
char a[1001][1001];
void dfs(int x, int y)
{
    if (x < 1 || x > link || y < 1 || y > m || a[x][y] == '0')
        return;
    a[x][y] = '0';
    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
}
int main()
{
    cin >> link >> m;
    memset(a, '0', sizeof(a));
    for (int i = 1; i <= link; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for (int i = 1; i <= link; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j] != '0')
            {
                ans++;
                dfs(i, j);
            }
    cout << ans << endl;
    return 0;

}
/*4 10
0111000011
1011110100
1011100111
0000000011*/