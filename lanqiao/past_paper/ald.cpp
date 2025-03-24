//
// Created by supanx on 25-3-20.
//
// 从2001年1月1日到2021年12月31日
#include <iostream>
#include <cmath>
using namespace std;
int da[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int ssum(int k) {
    int res = 0;
    while (k > 0) {
        res += k % 10;
        k /= 10;
    }
    return res;
}
int main() {
    int ans = 0;
    for (int y = 2001; y <= 2021; ++y) {
        bool leap = (y%4 == 0 && y%100 != 0) || (y%400 == 0);
        for (int m = 1; m <= 12; ++m) {
            int maxd = da[m]+(m == 2 && leap);
            for (int d = 1; d <= maxd; ++d) {
                int sum = ssum(y)+ssum(m)+ssum(d);
                int sq = sqrt(sum);
                if (sq*sq == sum) ans++;
            }
        }
    }
    cout << ans;
    
    return 0;
}