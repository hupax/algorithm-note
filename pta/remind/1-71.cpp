//
// Created by 沙枭 on 24-11-12.
// 二叉树
#include <vector>
#include <iostream>
using namespace std;
int link, m;
string ans;
int res(string &s) {
    int node = 1;
    for (auto i : s) {
        node = i == 'y' ? node * 2 : node * 2 + 1;
    }
    return node - (1 << link) + 1;
}
int main() {
    cin >> link >> m;
    while (m--) {
        cin >> ans;
        cout << res(ans) << endl;
    }
}