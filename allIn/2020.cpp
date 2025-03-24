//
// Created by 沙枭 on 2024/3/28.
//
#include "iostream"
#include "cmath"

using namespace std;

int main()
{
    int n;
    while (cin >> n && n > 0 && n <= 100)
    {
        auto * arr = new int [n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
//        排序
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - 1; ++j) {
                if (abs(arr[j]) < abs(arr[j + 1]))
                {
                    int t = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = t;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << ' ';
        }
        cout << endl;

        delete[] arr;
    }
}
