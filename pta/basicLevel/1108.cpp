//
// Created by 沙枭 on 2024/4/17.
//
// 1108 String复读机
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<char, int> umci;
    string line;
    cin >> line;
    for (char c : line)
        umci[c]++;
    int S = umci['S'];
    int t = umci['t'];
    int r = umci['r'];
    int i = umci['i'];
    int n = umci['n'];
    int g = umci['g'];
    while (S > 0 || t > 0 || r > 0 || i > 0 || n > 0 || g > 0)
    {
        if (S-- > 0) cout << "S";
        if (t-- > 0) cout << "t";
        if (r-- > 0) cout << "r";
        if (i-- > 0) cout << "i";
        if (n-- > 0) cout << "n";
        if (g-- > 0) cout << "g";
    }
}