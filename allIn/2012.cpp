//
// Created by 沙枭 on 2024/3/27.
//
#include "iostream"

using namespace std;

int main()
{
    int x, y;
    while (cin >> x >> y && x >= -39 && x <= 50 && y >= -39 && y <= 50)
    {
        if (x > y)
        {
            int t = x;
            x = y;
            y = t;
        }
        if (x == 0 && y == 0)
        {
            break;
        }
        bool flag = true;
        for (int i = x; i <= y; ++i) {
            int num = i * i + i + 41;
            if (num < 4 && num > -4)
            {
                flag = true;
            }
            for (int j = 2; j < num; ++j) {
                if (num % j == 0)
                {
                    flag = false;
                }
            }
        }
        if (flag)
        {
            cout << "OK" << endl;
        } else
        {
            cout << "Sorry" << endl;
        }
    }
}
