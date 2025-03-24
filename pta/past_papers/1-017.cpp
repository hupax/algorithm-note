//
// Created by 沙枭 on 2024/4/5.
//
// L1-017 到底有多二
#include "iomanip"
#include "bits/stdc++.h"
#include "string"
#include "iostream"

using namespace std;

int main()
{
    string line;
    while (cin >> line && line.empty() == 0)
    {
        int len = line.size();
        bool zF = line[0] == '-';

        int last = (int)(line[len - 1] - '0');
        bool jO = last % 2 == 0;

        int i = 0;
        if (zF) i++;
        double num2 = 0;
        for (; i < len; ++i) {
            if (line[i] == '2') num2++;
        }
        if (zF) len--;
        double result = num2 / len * 100.0;
        if (zF) result *= 1.5;
        if (jO) result *= 2.0;
        cout << fixed << setprecision(2);
        cout << result << "%" << endl;
    }
}