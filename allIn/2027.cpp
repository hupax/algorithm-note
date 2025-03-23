//
// Created by 沙枭 on 2024/3/28.
//
// 统计元音
#include "iostream"
#include "string"
#include "vector"

using namespace std;

int main()
{
    int n;
//    cin >> link;
//    cin.ignore();   // 忽略输入后残留的换行符！！！！！！！！！！！！！！！！！！！！！！！！！
    while (cin >> n)
    {
        string line;
        cin.ignore();
        vector<string> hh;
        for (int i = 0; i < n; ++i) {
            getline(cin, line);
            hh.push_back(line);
        }
//        cout << hh.size() << endl;
        int arr[5];
        for (const auto & i : hh) {
            for (int & j : arr)
            {
                j = 0;
            }
                for (int k = 0; k < i.length(); ++k)
                {
                    switch (i[k]) {
                        case 'a':
                            arr[0]++;
                            continue;
                        case 'e':
                            arr[1]++;
                            continue;
                        case 'i':
                            arr[2]++;
                            continue;
                        case 'o':
                            arr[3]++;
                            continue;
                        case 'u':
                            arr[4]++;
                            continue;
                    }
                }
            cout << 'a' << ':' << arr[0] << endl;
            cout << 'e' << ':' << arr[1] << endl;
            cout << 'i' << ':' << arr[2] << endl;
            cout << 'o' << ':' << arr[3] << endl;
            cout << 'u' << ':' << arr[4] << endl;
            cout << endl;
        }


    }
}