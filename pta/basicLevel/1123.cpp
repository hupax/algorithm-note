//
// Created by 沙枭 on 2024/4/14.
//
// 1123 舍入
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <iomanip>

using namespace std;

void kubiadd(string &s2)
{
//    reverse(s2.begin(), s2.end());
    if (s2[0] == '9')
    {
        s2[0] = '0';
        kubiadd(s2.substr(0, s2.size() - 1));
    }
    else s2[0] += 1;
}

int main()
{
    string line = "979";
    kubiadd(line);
    cout << line << endl;
}