//
// Created by 沙枭 on 24-5-8.
//
// 最长上升子序列
#include <iostream>
using namespace std;
int n, ans = 0;
int a[105], f[105];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        f[i] = 1;
        for (int j = 1; j < i; ++j)
        {
            if (a[j] < a[i])
            {
                f[i] = max(f[i], f[j] + 1);
            }
        }
        cout << f[i] << " ";
        ans = (ans, f[i]);
    }
    cout << endl << ans << endl;
}
/*
7
2 5 3 4 1 7 6
*/