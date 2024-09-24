//
// Created by 沙枭 on 2024/3/27.
//
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int si;
    while (cin >> si && si > 0)
    {
        int* ma = new int[si];
        int num;
        int result = 1;
        for (int i = 0; i < si; ++i) {
            cin >> num;
            ma[i] = num;
        }
        for_each(ma, ma + si, [&](int x) {
            if (x % 2 != 0)
            {
                result *= x;
            }
        });
        cout << result << endl;
    }
}
