//
// Created by 沙枭 on 2024/4/1.
//
#include "iostream"

using namespace std;

int main()
{
//    int r;
//    cin >> r;
    auto **arr = new int *[5];
    for (int i = 1; i <= 5; ++i) {
        arr[i-1] = new int[3];
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            arr[i][j] = j;
        }
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << arr[i][j];
        }
        cout << endl;
    }
    int m = sizeof(*arr) / sizeof(*arr[0]);
    cout << m;

    delete[] arr;
}