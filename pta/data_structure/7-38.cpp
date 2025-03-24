//
// Created by 沙枭 on 24-5-20.
//
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
priority_queue<int, vector<int>, greater<>> pq;
stack<int> st;
int main()
{
    int n, m, v;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> v;
        pq.push(v);
        if (pq.size() > m) {
            pq.pop();
        }
    }
    while (!pq.empty()) {
        st.push(pq.top());
        pq.pop();
    }
    while (!st.empty()) {
        cout << st.top();
        st.pop();
        if (!st.empty()) cout << " ";
    }
}
/*
在一行内按非递增顺序输出资产排前M位的大富翁的个人资产值。
 数字间以空格分隔，但结尾不得有多余空格。
输入样例:
8 3
8 12 7 3 20 9 5 18
输出样例:
20 18 12
 */