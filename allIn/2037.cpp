//
// Created by 沙枭 on 2024/3/30.
//
// 今年暑假不AC 贪心
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    int n;
    pair<int, int> a[105];
    while (cin >> n && n)
    {
        int count = 0, e = 0;
        for (int i = 1; i <= n; ++i)
            cin >> a[i].second >> a[i].first;
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i)
            if (a[i].second >= e)
            {
                count++;
                e = a[i].first;
            }
        cout << count << endl;
    }
}