//
// Created by 沙枭 on 24-5-18.
//
// 7-19 求链式线性表的倒数第K项
#include <iostream>
#include <queue>
using namespace std;
int x, t;
queue<int> q;
int main()
{
    cin >> x;
    while (cin >> t && t >= 0) {
        if (q.size() == x) {
            q.pop();
        }
        q.push(t);
    }
    if (q.size() != x)
        cout << "NULL" << endl;
    else cout << q.front() << endl;
}


/*
给定一系列正整数，请设计一个尽可能高效的算法，查找倒数第K个位置上的数字。
输入格式:
输入首先给出一个正整数K，随后是若干非负整数，最后以一个负整数表示结尾（该负数不算在序列内，不要处理）。

输出格式:
输出倒数第K个位置上的数据。如果这个位置不存在，输出错误信息NULL。

输入样例:
4 1 2 3 4 5 6 7 8 9 0 -1
输出样例:
7
 */
