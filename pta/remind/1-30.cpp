//
// Created by 沙枭 on 24-11-11.
//
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, m;
    string line;
    cin >> n;
    m = n;
    getchar();
    vector<string> st;
    while (m--) {
        getline(cin, line);
        st.push_back(line);
    }
    int l = 0;
    while (l < n) {
        int r = n - 1;
        while (r > 1) {
            if (st[l][0] != st[r][0] && st[l][0] != 'y' && st[r][0] != 'y') {
                cout << st[l].substr(2) << " " << st[r].substr(2) << endl;
                st[l][0] = st[r][0] = 'y';
                break;
            }
            r--;
        }
        l++;
    }
}
