//
// Created by 沙枭 on 2024/4/11.
//
// L1-054 福到了
#include "iostream"
#include "stack"
#include "string"

using namespace std;

int main()
{
    char c;
    int n;
    string line, t;
    bool flag = 1;
    stack<string> ss;
    cin >> c >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        t = line;
        reverse(line.begin(), line.end());
        if (t != line) flag = 0;
        replace(line.begin(), line.end(), '@', c);
        ss.push(line);
    }
    if (flag) cout << "bu yong dao le" << endl;
    while (!ss.empty())
    {
        cout << ss.top() << endl;
        ss.pop();
    }
}