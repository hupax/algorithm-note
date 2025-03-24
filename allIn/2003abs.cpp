//
// Created by 沙枭 on 2024/3/26.
//
#include "iostream"
#include "cmath"
#include "iomanip"

using namespace std;

int main()
{
    double num;

    cout << fixed << setprecision(2);
    while (cin >> num)
    {
        cout << abs(num) << endl;
    }
}
