//
// Created by 沙枭 on 2024/3/26.
//
#include <iostream>

using namespace std;

int main()
{
    char a, b, c, t;
    while (cin >> a >> b >> c) {
        if (a > b) {
            t = a;
            a = b;
            b = t;
        }
        if (a > c) {
            t = a;
            a = c;
            c = t;
        }
        if (b > c) {
            t = b;
            b = c;
            c = t;
        }
        cout << a << " " << b << " " << c << endl;
    }
}