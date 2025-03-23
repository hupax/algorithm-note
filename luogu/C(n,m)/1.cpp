//
// Created by supanx on 25-3-17.
//
#include <iostream>
using namespace std;

int64_t ans1(int n, int m) {
    int64_t ans = 1;
    for (int i = 0; i < min(n, m) - 1; i++) {
        ans *= n + m - 2 - i;
        ans /= i + 1;
    }
    return ans;
}

long long ans2(int n, int m) {
    long long ans = 1;
    for (long long i = 1; i <= m; i++) {
        ans *= n - m + i;
        ans /= i;
    }
    return ans;
}
int main() {
    
    cout << ans1(7, 3) << endl;
    cout << ans2(8, 2) << endl;
    
    return 0;
}