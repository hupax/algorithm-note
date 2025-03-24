//
// Created by 沙枭 on 2024/3/30.
//
// 三角形

#include "iostream"

using namespace std;

int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        if (m + 1 < 0) break;
        int a, b, c;
        cin >> a >> b >> c;
        if (a * b * c < 0 || a >= 1000 || b >= 1000 || c >= 1000) break;
        bool h = false;
        bool g = false;
        if (a + b > c && a < b + c && a + c > b) h = true;
        if (a - b < c && a > b - c && a - c < b) g = true;
        if(g & h) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}