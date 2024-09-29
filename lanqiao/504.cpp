//
// Created by 沙枭 on 24-9-28.
//
#include <iostream>
#include <bits/stdc++.h>
//#include <string>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    unordered_map<char, int> map;
    for (auto &c : line) {
        map[c]++;
    }
    vector<pair<char, int>> ans(map.begin(), map.end());
    sort(ans.begin(), ans.end(), [&] (pair<char, int> a, pair<char, int> b) {
        return a.second == b.second ? a.first < b.first : a.second > b.second;
    });
    
    cout << ans[0].first << endl;
    cout << ans[0].second << endl;
}