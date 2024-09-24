//
// Created by 沙枭 on 2024/3/27.
//
#include "iostream"
#include "iomanip"
#include "cmath"

using namespace std;

int main()
{
    int m;
    while (cin >> m && m > 0)
    {
        int n;
        for (int i = 0; i < m; ++i) {
            cin >> n;
            double sum = 0;
            if (n > 0 && n < 1000)
            {
                for (int j = 1; j <= n; ++j) {
                    sum += pow(-1, j + 1) * pow(j, -1);
                }
            }
            cout << fixed << setprecision(2);
            cout << sum << endl;
        }
    }
}
