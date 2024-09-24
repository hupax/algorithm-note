//
// Created by 沙枭 on 2024/4/5.
//
// L1-015 跟奥巴马一起画方块
#include "iostream"
#include "bits/stdc++.h"
#include "cmath"

using namespace std;

int main()
{
    int n;
    char c;
    while (cin >> n >> c && n > 2 && n < 22)
    {

        double rows = round(n / 2.0);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << c;
            }
            cout << endl;
        }
    }
}