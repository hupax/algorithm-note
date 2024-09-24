//
// Created by 沙枭 on 24-5-22.
//
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cstring>
#include <queue>
#include <map>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> mountain(4);
    for (auto &item : mountain) cin >> item;
    
    vector<int> ans;
    int a = 0, b = 0;
    for (int i = 1; i < mountain.size(); ++i) {
        if (mountain[i] - mountain[i - 1] > 0) {
            a = 1;
        }
        else if (mountain[i] - mountain[i - 1]) {
            if (a) ans.push_back(i - 1);
            a = 0;
        }
    }
    for (const auto &item : ans) cout << item << endl;
    return 0;
}