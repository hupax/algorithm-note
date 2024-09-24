//
// Created by 沙枭 on 24-5-8.
//
// 7-1 最大子列和问题
#include <iostream>
using namespace std;
const int M = 1e5;
int n, a[M], f[M], ans;
bool flag = 1;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        f[i] = max(a[i], f[i - 1] + a[i]);
        ans = max(ans, f[i]);
        if (a[i] >= 0) flag = 0;
    }
    if (flag) cout << 0 << endl;
    else cout << ans << endl;
}