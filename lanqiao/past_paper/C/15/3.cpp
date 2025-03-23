//
// Created by supanx on 25-3-15.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#define ll long long
using namespace std;
vector<string> ve;
unordered_map<string, int> f;
int n, pre = 0, ans;
string s;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        ve.push_back(s);
        pre += i;
        f[to_string(pre)] = 1;
    }
    f["1"] = f["2"] = 0;
    for (auto &it: ve) if (!f[it]) ans++;
    cout << ans;
    return 0;
}