//
// Created by 沙枭 on 2024/3/25.
//
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double x1, y1, x2, y2;
    double distance;

    while (std::cin >> x1 >> y1 >> x2 >> y2)
    {
        distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        std::cout << std::fixed << std::setprecision(2) << distance << std::endl;
    }
}
