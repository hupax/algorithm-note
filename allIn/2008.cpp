//
// Created by 沙枭 on 2024/3/27.
//
#include <iostream>

using namespace std;

int main()
{
    int n;
    while (cin >> n && n >= 0)
    {
        if (n == 0)
        {
            continue;
        }
        auto* arr = new double[n];
        double m;
        int f = 0;
        int l = 0;
        int z = 0;
        for (int i = 0; i < n; ++i) {
            cin >> m;
            arr[i] = m;
        }
        for (int i = 0; i < n; ++i) {
            if (arr[i] < 0)
            {
                f++;
            } else if (arr[i] > 0)
            {
                z++;
            } else
            {
                l++;
            }
        }
        delete[] arr;
        cout << f << ' ' << l << ' ' << z << endl;
    }
}