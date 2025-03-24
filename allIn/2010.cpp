//
// Created by 沙枭 on 2024/3/27.
//
#include "iostream"
#include "vector"

using namespace std;

int main()
{
    int m, n;
    while (cin >> m >> n && m >= 100 && m <= n && n <= 999)
    {
        vector<double> myArr;
        bool flag = true;
        while (m <= n)
        {
            int a, b, c, t;
            a = m % 10;
            b = m / 10 % 10;
            c = m / 100 % 10;

            t = a*a*a + b*b*b + c*c*c;

            if (t == m)
            {
                flag = false;
                myArr.push_back(t);
            }
            m++;

        }
        if (flag)
        {
            cout << "no" << endl;
        } else
        {
            for (int i = 0; i < myArr.size(); ++i) {
                cout << myArr[i] << ' ';
            }
            cout << endl;
        }
    }
}