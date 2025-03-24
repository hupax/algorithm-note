//
// Created by 沙枭 on 2024/4/11.
//
// L1-049 天梯赛座位分配
#include "iostream"

using namespace std;

int main()
{
    int n, m, max = 0, tot[105][105] = {0}, vis[105][105] = {0};
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        if (m > max) max = m;
        for (int j = 0; j < m * 10; ++j) {
            vis[i][j] = 1;
        }
    }
    int id = 1, flag = 1;
    for (int i = 0; i < max * 10; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (vis[j][i])
            {
                if (flag != j)
                {
                    tot[j][i] = id++;
                    flag = j;
                }
                else
                {
                    id += 1;
                    tot[j][i] = id++;
                    flag = j;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << "#" << i + 1 << endl;
        for (int j = 0; j < max * 10; ++j) {
            if (tot[i][j]) {
                cout << tot[i][j];
                if ((j + 1) % 10 == 0)
                    cout << endl;
                else cout << " ";
            }
        }
    }
}