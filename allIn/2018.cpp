//
// Created by 沙枭 on 2024/3/28.
//
/*
#include "iostream"

using namespace std;

int main()
{
    int n;
    while (cin >> n && n > 0 && n < 55)
    {
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            if (i < 5)
            {
                sum++;
            } else
            {
                sum += i - 3;
            }
        }
        cout << sum << endl;
    }
}
*/
// 递归！
#include "iostream"

using namespace std;

int calc(int x);

int main()
{
    int n;
    while (cin >> n && n > 0 && n < 55)
    {
        cout << calc(n) << endl;
    }
    return 0;
}

int calc(int x)
{
    if (x == 1) return 1;
    else if (x == 2) return 2;
    else if (x == 3) return 3;

    else return calc(x -1) + calc(x -3);
}
