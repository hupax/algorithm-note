//
// Created by 沙枭 on 2024/4/17.
//
// 1102 教超冠军卷
// Created on 2024/04/17.
#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

bool cmp(pair<string, int> &a, pair<string, int> &b)
{
    return a.second > b.second;
}

int main()
{
    map<string, int> msi1;
    map<string, int> msi2;
    int n;
    cin >> n;
    string id;
    int price, num;
    while (n--)
    {
        cin >> id >> price >> num;
        msi1[id] = num;
        msi2[id] = price * num;
    }
    vector<pair<string, int>> vp1(msi1.begin(), msi1.end());
    vector<pair<string, int>> vp2(msi2.begin(), msi2.end());

    sort(vp1.begin(), vp1.end(), cmp);
    sort(vp2.begin(), vp2.end(), cmp);

    auto it = vp1.begin();
    auto t = vp2.begin();

    cout << it->first << " " << it->second << endl;
    cout << t->first << " " << t->second << endl;
}