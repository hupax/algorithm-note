//
// Created by 沙枭 on 2024/3/30.
//
// 亲和数
#include "iostream"

using namespace std;

int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        int a, b;
        int i = 1;
        int j = 1;
        int gg = 0;
        int hh = 0;
        cin >> a >> b;
        while (i < a)
        {
            if (a % i == 0) gg += i;
            i++;
        }
        while (j < b)
        {
            if (b % j == 0) hh += j;
            j++;
        }
        if (gg == b && hh == a) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}