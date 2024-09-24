//
// Created by 沙枭 on 2024/4/5.
//
#include "bits/stdc++.h"
#include "iostream"

using namespace std;

int main()
{
    string line;
    string subLine;
    getline(cin, line, '\n');
    getline(cin, subLine, '\n');
    for (auto t : subLine)
    {
        int f = line.find(t);
        while (f != -1)
        {
            line.erase(f, 1);
            f = line.find(t);
        }
    }
    cout << line << endl;
}