//
// Created by 沙枭 on 24-5-11.
//
#include <iostream>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;
int x, y;
int main()
{
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<pair<int, int>> ve;
    while (iss >> x >> y)
    {
        if (y && x)
            ve.emplace_back(x * y, y - 1);
    }
    for (auto &f : ve)
    {
        cout << f.first << " " << f.second;
        if (f != ve.back()) cout << " ";
    }
}