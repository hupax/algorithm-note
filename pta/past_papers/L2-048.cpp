//
// Created by 沙枭 on 2024/4/24.
//
// L2-048 寻宝图
#include <iostream>
#include <iostream>
#include <vector>

using namespace std;

bool flag;
int link, m;
int ans = 0, bns = 0;
vector<vector<char>> ma;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
    if (x < 0 || x >= link || y < 0 || y >= m || ma[x][y] == '0')
        return;
    if (ma[x][y] > '1' && flag) {
        bns++;
        flag = 0;
    }
    ma[x][y] = '0';
    for (int i = 0; i < 4; ++i)
        dfs(x + dx[i], y + dy[i]);
}

int main() {
    cin >> link >> m;
    ma.resize(link, vector<char>(m));
    for (int i = 0; i < link; ++i)
        for (int j = 0; j < m; ++j)
            cin >> ma[i][j];
    for (int i = 0; i < link; ++i)
        for (int j = 0; j < m; ++j)
            if (ma[i][j] != '0')
            {
                flag = 1;
                ans++;
                dfs(i, j);
            }
    cout << ans << " " << bns << endl;
    return 0;
}