//
// Created by 沙枭 on 2024/3/29.
//
// 统计给定文本文件中汉字的个数。

#include "iostream"
#include "string"

using namespace std;

int main()
{
    int n;
    cin >> n;
    getchar();
    char c;
    while (n--)
    {
        int sum = 0;
        string s;
        getline(cin, s);
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] < 0) sum++;
        }
        cout << sum / 2 << endl;

    }
}