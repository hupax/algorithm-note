//
// Created by 沙枭 on 2024/3/30.
//
// Sum Problem
#include "iostream"

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
//        cout << 0.5 * link * (1 + link) << endl;
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += i;
        }
        cout << sum << endl;
    }
}