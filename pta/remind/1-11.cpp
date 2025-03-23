//
// Created by 沙枭 on 24-11-10.
//
#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    getline(cin, a, '\n');
    getline(cin, b, '\n');
    
    string ans = "";
    unordered_set<char> rmc(b.begin(), b.end());
    for (auto &c : a) {
        if (rmc.count(c) == 0) ans += c;
    }
    cout << ans << endl;
}