//
// Created by 沙枭 on 2024/4/19.
//
// 1100 校庆
// Created on 2024/04/19.
#include <bits/stdc++.h>
#include <iostream>


using namespace std;

int main()
{
    int n;
    vector<string> ves(n);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> ves[i];
    int m, sum = 0;
    string xyou, laib;
    cin >> m;
    string line, bithXy = "20191231", bithLaib = "20191231";
    while (m--)
    {
        cin >> line;
        string bith = line.substr(6, 8);
        if (bith < bithLaib)
        {
            bithLaib = bith;
            laib = line;
        }
        if (count(ves.begin(), ves.end(), line))
        {
            sum++;
            if (bith < bithXy)
            {
                bithXy = bith;
                xyou = line;
            }
        }
    }
    if (sum) cout << sum << endl << xyou << endl;
    else cout << "0" << endl << laib << endl;
}