//
// Created by 沙枭 on 24-5-8.
//
// 最大上升子序列和
#include <iostream>
using namespace std;
int link, ans = -99999999;
int a[105], f[105];
int main()
{
    cin >> link;
    for (int i = 1; i <= link; ++i)
    {
        cin >> a[i];
        f[i] = a[i];
        for (int j = 1; j < i; ++j)
        {
            if (a[j] < a[i])
            {
                f[i] = max(f[i], a[i] + f[j]);
            }
        }
//        cout << f[i] << " ";
        ans = max(ans, f[i]);
    }
    cout << endl << ans << endl;
}
/*
7
2 5 3 4 1 7 6
 */
