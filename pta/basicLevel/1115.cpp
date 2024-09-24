//
// Created by 沙枭 on 2024/4/18.
//
// 1115 裁判机
// Created on 2024/04/18.
#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n1, n2;
    int n, m;
    cin >> n1 >> n2 >> n >> m;
    vector<vector<int>> vevi(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> vevi[i][j];
    vector<int> num;
    vector<int> cNum;
    num.push_back(n1);
    num.push_back(n2);
    cNum.push_back(abs(n1 - n2));
    map<int, int> maii; // 已经淘汰的人
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (maii.count(j + 1)) continue;
            if (!count(num.begin(), num.end(), vevi[j][i]) &&
                count(cNum.begin(), cNum.end(), vevi[j][i]))
            {
                num.push_back(vevi[j][i]);
                for (int &r: num)
                    cNum.push_back(abs(vevi[j][i] - r));
            } else
                maii[j + 1] = i + 1;
        }
    }
    for (auto &[k, v] : maii)
        cout << "Round #" << v << ": " << k << " is out." << endl;

}