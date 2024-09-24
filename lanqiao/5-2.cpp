//
// Created by 沙枭 on 2024/5/3.
//
//2. 欢迎参加福建省大学生程序设计竞赛【算法赛】
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <set>

using namespace std;

int main()
{
    int n, a, b, m = 0;
    unordered_map<int, set<int>> uu;
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        if (uu.find(a) != uu.end())
            m++;
        else if (uu[a].find(b) != uu[a].end())
            m++;
        if (n&1)

    }
  // 请在此输入您的代码
  return 0;
}