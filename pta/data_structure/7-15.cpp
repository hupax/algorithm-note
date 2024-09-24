//
// Created by 沙枭 on 24-5-18.
//
// 7-15 QQ帐户的申请与登陆
#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;
int n;
string cmd, id, pw;
unordered_map<string, string> user;
int main()
{
    cin >> n;
    while (n--)
    {
        cin >> cmd >> id >> pw;
        if (cmd == "L")
        {
            if (user.find(id) != user.end())
            {
                if (pw == user[id])
                    cout << "Login: OK" << endl;
                else cout << "ERROR: Wrong PW" << endl;
            }
            else cout << "ERROR: Not Exist" << endl;
        }
        else
        {
            if (user.find(id) == user.end())
            {
                user[id] = pw;
                cout << "New: Ok" << endl;
            }
            else cout << "ERROR: Exist" << endl;
        }
    }
}

/*
输入样例:
5
L 1234567890 myQQ@qq.com
N 1234567890 myQQ@qq.com
N 1234567890 myQQ@qq.com
L 1234567890 myQQ@qq
L 1234567890 myQQ@qq.com

输出样例:
ERROR: Not Exist
New: OK
ERROR: Exist
ERROR: Wrong PW
Login: OK
 
 */