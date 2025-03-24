//
// Created by 沙枭 on 2024/3/26.
//
#include "iostream"
#include "iomanip"
#include "cmath"

using namespace std;

int main()
{
    double r;
    double P = 3.1415927;
    double v = 0;
    cout << fixed << setprecision(3);
    while (cin >> r)
    {
        v = (double)4/3*P* pow(r,3);
        cout << v << endl;
    }
}