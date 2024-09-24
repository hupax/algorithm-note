//
// Created by 沙枭 on 2024/3/26.
//
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double km = 0;
    double cost = 0;
    int min = 0;

    cin >> km >> min;
    for(; min >= 5; min -= 5)
    {
        cost += 2;
    }
    if(km > 0)
    {
        cost += 10;
    }
    if(km > 10)
    {
        cost += (km - 10) * 3;
        km -= km -10;
    }
    if(3 < km && km <= 10)
    {
        cost += (km - 3) * 2;
    }
    cout << fixed << setprecision(0);
    cout << cost << endl;

}