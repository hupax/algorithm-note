//
// Created by 沙枭 on 24-5-8.
//
// 14. CLZ银行问题
#include <iostream>
#include <queue>
using namespace std;
int link;
queue<string> vip;
queue<string> nip;
int main()
{
    cin >> link;
    string type, name, p;
    for (int i = 0; i < link; ++i)
    {
        cin >> type;
        if (type == "IN")
        {
            cin >> name >> p;
            if (p == "N")
            {
                nip.push(name);
            }
            else vip.push(name);
        }
        else
        {
            cin >> p;
            if (p == "N")
            {
                nip.pop();
            }
            else vip.pop();
        }
    }
    while (!vip.empty())
    {
        cout << vip.front() << endl;
        vip.pop();
    }
    while (!nip.empty())
    {
        cout << nip.front() << endl;
        nip.pop();
    }
    // 请在此输入您的代码
    return 0;
}