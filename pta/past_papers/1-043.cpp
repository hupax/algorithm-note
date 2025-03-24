//
// Created by 沙枭 on 2024/4/8.
//
// L1-043 阅览室
// Created on 2024/04/09
#include<bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

int date, id, h, m, num,sTime[1005];
double tot;
char c, t;
bool vis[1005];

int main()
{
    cin >> date;
    while (date--)
    {
        memset(sTime, 0, sizeof(sTime));
        memset(vis, 0, sizeof(vis));
        num = 0;
        tot = 0;
        while (1)
        {
            cin >> id >> c >> h >> t >> m;
            if (id == 0) break;
            if (c == 'E' && !vis[id]) continue;
            else if (c == 'S')
            {
                vis[id] = 1;
                sTime[id] = h * 60 + m;
            }
            else if (c == 'E')
            {
                vis[id] = 0;
                tot += h * 60 + m - sTime[id];
                num++;
            }
        }
        if (num) cout << num << " " << round(tot / num * 1.0) << endl;
        else cout << "0 0" << endl;
    }
}
