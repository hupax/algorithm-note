//
// Created by supanx on 25-3-14.
//
// 老鼠和奶酪
/* 思路
 * 求最大得分 ---> 求 A 吃的 k 块 加 B 吃的 n - k 块得分最大
 * 1.假设 B 先吃 n 块 即 reward2[i] 全吃
 *  --> 找出 A 吃哪 k 块 使得分最大
 * 2.可以引入一个数组, 记录 reward1[i] 和 reward2[i] 的差值 取差值最大的 k 个
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k) {
    int n = reward1.size(), ans = 0;
    vector<int> ve(n);
    for (int i = 0; i < n; i++) {
        ve[i] = reward1[i] - reward2[i];
        ans += reward2[i];
    }
    sort(ve.begin(), ve.end());
    while (k--) {
        ans += ve.back();
        ve.pop_back();
    }
    return ans;
}
int main() {
    
    return 0;
}