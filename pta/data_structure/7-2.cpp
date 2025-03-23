//
// Created by 沙枭 on 24-5-8.
//
// 7-2 一元多项式的乘法与加法运算
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int link, m, x, y, u, w;
int main()
{
    cin >> link;
    unordered_map<int, int> ve;
    for (auto i = 0; i < link; ++i)
    {
        cin >> u >> w;
        ve[w] = u;
    }
    unordered_map<int, int> us;
    unordered_map<int, int> uw(ve.begin(), ve.end());
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y;
        for (auto &k : ve)
        {
            us[y + k.first] += x * k.second;
        }
        uw[y] += x;
    }
    vector<pair<int, int>> vef(us.begin(), us.end());
    sort(vef.begin(), vef.end(), [] (pair<int, int> &a, pair<int, int> &b)
    {
      return a.first > b.first;
    });
    for (auto &f : vef)
    {
        if (f.second)
        {
            cout << f.second << " " << f.first;
            if (f != vef.back()) cout << " ";
        }
    }
    cout << endl;
    vector<pair<int, int>> vis(uw.begin(), uw.end());
    sort(vis.begin(), vis.end(), [] (pair<int, int> &a, pair<int, int> &b)
    {
      return a.first > b.first;
    });
    for (auto &f : vis)
    {
        if (f.second)
        {
            cout << f.second << " " << f.first;
            if (f != vis.back()) cout << " ";
        }
    }
}
/*
输入样例:

4 3 4 -5 2  6 1  -2 0
3 5 20  -7 4  3 1

4 3 4 -5 2  -3 1  -2 0
3 5 20  -7 4  3 1
输出样例:

15 24  -25 22  30 21  -10 20  -21 8  35 6  -42 5  14 4  9 5  -15 3  18 2  -6 1
15 24  -25 22  30 21  -10 20  -21 8  35 6  -33 5  14 4  -15 3  18 2 -6 1

15 24  -25 22  30 21  -10 20  -21 8  35 6  -33 5  14 4  -15 3  18 2  -6 1
15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0
 */