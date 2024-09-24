//
// Created by 沙枭 on 2024/3/30.
//
// 进制转换
#include "iostream"
#include "vector"
#include "cmath"

using namespace std;


int main()
{
/*    int n, r;
    while (cin >> n >> r && r >= 2 && r <= 16)
    {
        vector<char> arr;
        bool flag = false;
        if (n < 0) flag = true;
        n = abs(n);
        int gg = n / r;
        int hh = n % r;
        char R[6];
        for (int i = 0; i < 6; ++i)
        {
            R[i] = (char)(i + 65);
        }
        if (hh < 10) arr.push_back((char)(hh + 48));
        else arr.push_back(R[hh - 10]);

        while (gg >= r)
        {
            gg /= r;
            hh = gg % r;
            if (hh < 10) arr.push_back((char)(hh + 48));
            else arr.push_back(R[hh - 10]);
        }
        if (gg < r && gg != 0)
        {
            if (gg < 10) arr.push_back((char)(gg + 48));
            else arr.push_back(R[gg - 10]);
        }

        if (flag) cout << '-';
        for (int i = arr.size(); i >= 0; ++i) {
            cout << arr[i];
        }
        cout << endl;
        arr.clear();
    }*/
    int n, r;
    vector<int> vt;
    char type[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                     '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while (cin >> n >> r) {
        if (n < 0) {  //若为负则添加 - 号
            cout << "-";
            n = -n;
        }
        if (!n) cout << "0";  //若n为0则输出0
        while (n != 0) {
            vt.push_back(n % r);
            n /= r;
        }
        for (int i = vt.size() - 1; i >= 0; i--) {
            cout << type[vt[i]];  //余数对应type输出
        }
        cout << endl;
        vt.clear();
    }
    return 0;
}
