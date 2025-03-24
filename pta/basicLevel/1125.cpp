//
// Created by 沙枭 on 2024/4/14.
//
// 1125 子串与子列
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line, s;
    cin >> line >> s;
    int si = 0, pi = 0, st = line.find(s[0]), ans = INT_MAX;
    string result;
    while (si < line.size()) {
        if (line[si] == s[pi]) {
            pi++;
            
            if (pi == s.size()) {
                int len = si - st;
                if (len < ans) {
                    ans = len;
                    result = line.substr(st, len + 1);
                }
                pi = 0;
                si = st++;
            }
        }
        si++;
    }
    cout << result << endl;
}
/*
输入样例：
atpaaabpabttpcat
pat
输出样例：
pabt
 */