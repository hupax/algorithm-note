//
// Created by 沙枭 on 2024/3/30.
//
// 人见人爱A^B
#include "iostream"
#include "cmath"

using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b && (a || b))
    {
        int s = a;
        for (int i = 1; i < b; ++i) {
            s = s * a % 1000;
        }
        cout << s;
        cout << endl;
    }
}