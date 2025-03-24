//
// Created by 沙枭 on 2024/3/28.
//
#include "iostream"
#include "iomanip"

using namespace std;

int main()
{
    int n, m;
    cout << fixed << setprecision(2);
    while (cin >> n >> m && n > 0 && m > 0 && n <= 50 && m <= 5)
    {
        auto ** arr = new double *[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = new double [m];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < n; ++i) {
            double ssum = 0;
            for (int j = 0; j < m; ++j) {
                ssum += arr[i][j];
            }
            cout << ssum / m << ' ';
        }
        cout << endl;

        auto * ll = new double [m];
        for (int i = 0; i < m; ++i) {
            double sum = 0;
            for (int j = 0; j < n; ++j) {
                sum += arr[j][i];
            }
            cout << sum / n << ' ';
            ll[i] = sum / n;
        }
        cout << endl;

        int nb = 0;
        for (int i = 0; i < n; ++i) {
            bool flag = true;
            for (int j = 0; j < m; ++j) {
                if (arr[i][j] < ll[j])
                {
                    flag = false;
                }
            }
            if (flag)
            {
                ++nb;
            }
        }
//        cout << fixed << setprecision(0);
        cout << nb << endl;

        delete[] arr;
        delete[] ll;
    }
}