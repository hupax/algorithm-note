//
// Created by 沙枭 on 2024/3/28.
//
#include "iostream"

using namespace std;

int main() {
    int n;
    while (cin >> n && n > 0 && n < 100) {
        auto *arr = new int[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        int  br[] = {100, 50, 10, 5, 2, 1};

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 6; ++j) {
                if (arr[i] >= br[j])
                {
                    int t = 0;
                    t = arr[i] / br[j];
                    sum += t;
                    arr[i] -= t * br[j];
                }
            }
        }
        cout << sum << endl;

        delete[] arr;
    }
}