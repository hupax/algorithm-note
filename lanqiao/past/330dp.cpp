//
// Created by 沙枭 on 24-5-5.
//
// 铺设道路
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, d, sum = 0, pre;
    cin >> n >> d;
    sum += d;
    pre = d;
    for (int i = 1; i < n; ++i)
    {
        cin >> d;
        if (d > pre)
        {
            sum += d - pre;
        }
        pre = d;
    }
    cout << sum;
    // 请在此输入您的代码
    return 0;
}
/*输入
6
4 3 2 5 3 5
copy
输出
9
 */