//
// Created by 沙枭 on 2024/4/29.
//
// 奇偶排序，算法塞;
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int link, vis[100005];
bool cmp(int &a, int &b)
{
    bool x = a % 2 == 0;
    bool y = b % 2 == 0;
    if (x && !y) return a > b;
    else if (!x && y) return a < b;
    else return a < b;
}
int main()
{
    cin >> link;
    for (int i = 0; i < link; ++i)
        cin >> vis[i];
    sort(begin(vis), end(vis), cmp);
    for (int i = 0; i < link; ++i)
    {
        if (i != 0) cout << " ";
        cout << vis[i];
    }
  // 请在此输入您的代码
  return 0;
}