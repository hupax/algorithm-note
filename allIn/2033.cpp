//
// Created by 沙枭 on 2024/3/30.
//
// 人见人爱A+B
#include "iostream"

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int h = 0;
        int m = 0;
        int s = 0;
        int arr[2][3] = {0};
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                cin >> arr[i][j];
            }
            h += arr[i][0];
            m += arr[i][1];
            s += arr[i][2];
        }
        while (s > 60)
        {
            m += s / 60;
            s %= 60;
        }
        while (m > 60)
        {
            h += m / 60;
            m %= 60;
        }
        cout << h << ' ' << m << ' ' << s << endl;
    }
}