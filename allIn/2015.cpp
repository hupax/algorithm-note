//
// Created by 沙枭 on 2024/3/27.
//
#include "iostream"

using namespace std;

int main()
{
    int n, m;
    while (cin >> n >> m && n > 0 && n <=100 && m > 0)
    {
        if (m > n)
        {
            int t = n;
            m = n;
            n = t;
        }
        auto* arr = new int[n];

        for (int i = 0; i < n; ++i) {
            arr[i] = 2 * (i + 1);
        }

        int sp = n % m;
        for (int i = 0; i < n - sp; i += m) {
            int sum = 0;
            for (int j = 0; j < m; ++j) {
                sum += arr [i + j];
            }
            if (sum)
            {
                cout << sum / m << ' ';
            }
        }
        int su = 0;
        if (n % m != 0)
        {
            for (int i = 0; i < sp; ++i) {
                su += arr[n - i - 1];
            }
            cout << su / sp;
        }
        cout << endl;

        delete[] arr;
    }
}
