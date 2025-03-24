//
// Created by supanx on 25-3-12.
//
#include <iostream>
using namespace std;
int main() {
    // 请在此输入您的代码
    // ans = 10115204 * (1 + 20230408);
//    long long ll = 10115204 * 20230409;
//    cout << ll << endl;
    int ans[17] = {0};
    int a[8] = {4, 0, 2, 5, 1, 1, 0, 1};
    int b[8] = {9, 0, 4, 0, 3, 2, 0, 2};
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            ans[i + j] += a[i] * b[j];
        }
    }
    for (int i = 16; i >= 0; i--) {
        if (ans[i] >= 10) {
            ans[i - 1] += ans[i] / 10;
            ans[i] %= 10;
        }
    }
    int p = 16;
    while (ans[p] == 0 && p > 0) {
        p--;
    }
    for (int i = p; i >= 0; i--) {
        cout << ans[i];
    }
    return 0;
}
