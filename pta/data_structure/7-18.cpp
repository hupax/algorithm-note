//
// Created by 沙枭 on 24-5-18.
//
// 7-18 银行业务队列简单模拟
#include <iostream>
#include <queue>
#include <sstream>
using namespace std;
queue<int> aq;
queue<int> bq;
int n, m;
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        if (m & 1) aq.push(m);
        else bq.push(m);
    }
    while (!aq.empty() || !bq.empty()) {
        bool flag = false;
        if (!aq.empty()) {
            flag = true;
            cout << aq.front();
            aq.pop();
            if (!aq.empty()) {
                cout << " " << aq.front();
                aq.pop();
            }
        }
        if (flag && !bq.empty()) cout << " ";
        if (!bq.empty()) {
            cout << bq.front();
            bq.pop();
        }
        if (!aq.empty() || !bq.empty())
            cout << " ";
    }
    cout << endl;
    return 0;
}