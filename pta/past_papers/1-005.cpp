//
// Created by 沙枭 on 2024/4/7.
//
// L1-005 考试座位号
#include "iostream"
#include "map"
#include "string"

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, string> map1;
    map<int, int> map2;
    while (n--)
    {
        string id;
        int shiJi, zuoHao;
        cin >> id >> shiJi >> zuoHao;
        map1[shiJi] = id;
        map2[shiJi] = zuoHao;
    }
    int g;
    cin >> g;
    int m;
    for (int i = 0; i < g; ++i)
    {
        cin >> m;
        cout << map1[m] << " " << map2[m] << endl;
    }
}
/*
4
3310120150912233 2 4
3310120150912119 4 1
3310120150912126 1 3
3310120150912002 3 2
2
3 4

3310120150912002 2
3310120150912119 1
 */