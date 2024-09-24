//
// Created by 沙枭 on 2024/4/4.
//
#include "iostream"

using namespace std;

int powPp(double x, double y)
{
    if (y == 0) return 1;
    else if (y < 0) return 1 / powPp(x, -y);
    else return x * powPp(x, y - 1);
}

int main()
{
    cout << powPp(3, 2);
}