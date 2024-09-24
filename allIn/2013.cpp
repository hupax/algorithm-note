//
// Created by 沙枭 on 2024/3/27.
//
#include "iostream"

using namespace std;

int main()
{
    int n;
    while (cin >> n && n > 1 && n < 30)
    {
        int num = 1;
        while (n > 1) {
            num = (num + 1 ) * 2;
            n--;
        }
        cout << num << endl;
    }
}
