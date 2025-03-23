//
// Created by 沙枭 on 24-5-8.
//
// 最大连续子段和
#include <iostream>
using namespace std;
int link, f[105], a[105], ans = -99999999;
int main()
{
    cin >> link;
    for (int i = 1; i <= link; ++i)
    {
        cin >> a[i];
        f[i] = max(a[i], f[i - 1] + a[i]);
        ans = max(ans, f[i]);
//        cout << f[i] << " ";
    }
    cout << endl << ans << endl;
}
/*
8
-2 10 8 -4 7 5 -29 10
 */
