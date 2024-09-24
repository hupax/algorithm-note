//
// Created by 沙枭 on 24-5-8.
//
// 最大连续子段积
#include <iostream>
using namespace std;
int n, a[105], f[105], d[105], ans;
int main()
{
    cin >> n;
//    cin >> a[1];
//    f[1] = d[1] = ans = a[1];
//    cout << f[1] << " ";
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        for (int j = 1; j <= i; ++j)
        {
            f[i] = max(max(a[i], f[j - 1] * a[i]), d[j - 1] * a[i]);
            d[i] = min(min(a[i], f[j - 1] * a[i]), d[j - 1] * a[i]);
        }
        ans = max(ans, f[i]);
        cout << f[i] << " ";
    }
    cout << endl << ans << endl;
}