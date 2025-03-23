//
// Created by 沙枭 on 2024/3/30.
//
// 杨辉三角

#include "iostream"

using namespace std;

int main()
{
    int n;
    while (cin >> n && n > 0 && n < 31)
    {
        auto ** arr = new int *[n];
        for (int i = 1; i <= n; ++i) {
            arr[i -1] = new int [i];
        }
        for (int i = 0; i < n; ++i) {
            arr[i][0] = 1;
            arr[i][i] = 1;
        }
        for (int i = 2; i < n; ++i) {
            for (int j = 1; j < i; ++j) {
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i + 1; ++j) {
                if (j == i) cout << arr[i][j] << endl;
                else cout << arr[i][j] << ' ';
            }
        }


        delete[] arr;
        cout << endl;
    }
}
/*
#include <iostream>
using namespace std;
int main() {
    int link, num[30][30] = {0};
    while (cin >> link) {
        for (int i = 0; i < link; i++) {
            num[i][0] = 1;
            num[i][i] = 1;
            for (int j = 1; j < i; j++) {
                num[i][j] = num[i - 1][j] + num[i - 1][j - 1];  //按公式计算
            }
            for (int x = 0; x <= i; x++) {
                if (x == 0)
                    cout << num[i][x];
                else
                    cout << " " << num[i][x];
                if (i == x) cout << endl;  //换行
            }
        }
        cout << endl;
    }
    return 0;
}*/
