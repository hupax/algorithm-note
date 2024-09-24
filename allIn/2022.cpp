//
// Created by 沙枭 on 2024/3/28.
//
#include "iostream"
#include "cmath"

using namespace std;

int main()
{
    int m, n;
    while (cin >> m >> n && m > 0 && n > 0)
    {
        auto ** arr = new int* [m];
        for (int i = 0; i < m; ++i) {
            arr[i] = new int [n];
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> arr[i][j];
            }
        }
        int max = abs(arr[0][0]);
        int x = 0;
        int y = 0;
         for (int i = 0; i < m; ++i)
         {
            for (int j = 0; j < n; ++j)
            {
                if (abs(arr[i][j]) > abs(max))
                {
                    max = arr[i][j];
                    x = i;
                    y = j;
                }
            }
        }
         cout << x + 1 << ' ' << y + 1 << ' ' << max << endl;

         delete[] arr;
    }
}