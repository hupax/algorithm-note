//
// Created by 沙枭 on 2024/3/27.
//
#include "iostream"
#include "cmath"
#include "iomanip"

using namespace std;

int main()
{
    double n;
    int m;
    while (cin >> n >> m && n > 0 && m > 0)
    {
        auto* arr = new double[m];
        arr[0] = n;
        for (int i = 1; i < m; ++i) {
            n = sqrt(n);
            arr[i] = n;
        }
        double sum = 0;
        for (int i = 0; i < m; ++i) {
            sum += arr[i];
        }
        cout << fixed << setprecision(2);
        cout << sum << endl;

        delete[] arr;
    }
}
