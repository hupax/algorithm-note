//
// Created by 沙枭 on 2024/4/19.
//
// 1097 矩阵行平移
#include <iostream>
// Creaated on 2024/04/19.
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, x;
    cin >> n >> k >> x;
    vector<vector<int>> vevi(n, vector<int>(n));
    for (auto &i : vevi)
        for (auto &j : i)
            cin >> j;
    int t = 1;
    for (int i = 0; i < n; i += 2)
    {
        for (int j = 0; j < t; ++j)
        {
            vevi[i].pop_back();
            vevi[i].insert(vevi[i].begin(), x);
        }
        t++;
        if (t > k) t = 1;
    }
    for (int i = 0; i < n; ++i)
    {
        int sum = 0;
        for (int j = 0; j < n; ++j)
            sum += vevi[j][i];
        if (i != 0) cout << " ";
        cout << sum;
    }
}