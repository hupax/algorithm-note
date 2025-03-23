//
// Created by 沙枭 on 24-10-10.
//
// 二分
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int binary_search(int a, int b) {
    int l = 1, r = 1e9;
    while (l < r) {
        int mid = l + r >> 1;
        if (a / mid > b) l = mid + 1;
        else r = mid;
    }
    return l;
}

int main() {
    /*
        b * v <= a
        (b + 1) * v > aa
    */
    // 请在此输入您的代码
    int n, a, b, minV = 1, maxV = 1e9;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        minV = max(minV, binary_search(a, b));
        maxV = min(maxV, binary_search(a, b - 1) - 1);
    }
    cout << minV << " " << maxV << endl;
    return 0;
}