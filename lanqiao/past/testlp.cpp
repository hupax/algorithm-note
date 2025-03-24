//
// Created by 沙枭 on 2024/4/25.
//
#include <iostream>
#include <algorithm>
#include <cmath>
#include <bitset>
using namespace std;


int main() {
    // 111
    string s = "111";
//    cin >> s;
    int x = stoi(s, 0, 2); // base=2
    x = x >> 1;
    cout << bitset<8>(x);
    return 0;
}

// 5 3
//10110
//11010