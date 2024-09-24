//
// Created by 沙枭 on 2024/4/18.
//
// L3-002 特殊堆栈
// Created on 2024/04/18.
#include <bits/stdc++.h>
#include <stack>
#include <iostream>

using namespace std;

int main()
{
    int n;
    string line;
    stack<int> sta;
    vector<int> ve;
    cin >> n;
    getchar();
    while (n--)
    {
        getline(cin, line);
        if (sta.size() == 0 && (line == "Pop" || line == "PeekMedian"))
        {
            cout << "Invalid" << endl;
            continue;
        }
        if (line == "Pop")
        {
            cout << sta.top() << endl;
            for (auto i = ve.begin(); i != ve.end() ; ++i)
                if (*i == sta.top())
                {
                    ve.erase(i);
                    break;
                }
            sta.pop();
            continue;
        }
        if (line.substr(0, 4) == "Push")
        {
            int key = stoi(line.substr(5));
            sta.push(key);
            ve.push_back(key);
            continue;
        }
        if (line == "PeekMedian")
        {
            sort(ve.begin(), ve.end());
            int len = ve.size();
            if (len % 2 == 0) len /= 2;
            else len = (len + 1) / 2;
            cout << ve[len - 1] << endl;
        }

    }
}