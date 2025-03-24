//
// Created by 沙枭 on 24-11-11.
//
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<int, int> umap;
    while (n--) {
        int k;
        cin >> k;
        while (k--) {
            int m;
            cin >> m;
            umap[m]++;
        }
    }
    vector<pair<int, int>> res(umap.begin(), umap.end());
    sort(res.begin(), res.end(), [] (pair<int, int> &a, pair<int, int> &b) {
      return a.second == b.second ? a.first > b.first : a.second > b.second;
    });
    cout << res[0].first << " " << res.front().second << endl;
}
