//
// Created by 沙枭 on 2024/4/15.
//
// 1119 胖达与盆盆奶
#include <iostream>
#include <bits/stdc++.h>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vi(n);
    map<int, int> mii;
    for (int &i : vi)
    {
        cin >> i;
        mii[i] = 200;
    }
//    10
//180 160 100 150 145 142 138 138 138 140
    while (1)
    {
        for (int i = 1; i < n; ++i)
        {
            int e = mii[vi[i - 1]], r = mii[vi[i]];
            if (vi[i - 1] > vi[i] && e <= r)
                mii[vi[i - 1]] += 100;
            else if (vi[i - 1] < vi[i] && e >= r)
                mii[vi[i]] += 100;
        }
        bool ff = 1;
        for (int i = 1; i < n; ++i)
        {
            int e = mii[vi[i - 1]], r = mii[vi[i]];
            if (vi[i - 1] > vi[i] && e <= r)
            {
                ff = 0;
                break;
            }
        }
        if (ff) break;
    }
    /*int e = mii[vi[0]], r = mii[vi[1]];
    cout << mii[vi[0]] << " " << mii[vi[1]] << endl;
    bool c = e <= r;
    bool b = mii[vi[0] < mii[vi[1]]];
    bool a = 200 <= 200;
    cout << b << " " << a << " " << c << endl;*/
    for (int &i : vi)
        cout << mii[i] << " ";
    cout << endl;
}