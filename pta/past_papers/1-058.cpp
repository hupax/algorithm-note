//
// Created by 沙枭 on 2024/4/8.
//
// L1-058 6翻了
#include <iostream>

using namespace std;

int main()
{
    string line;
    getline(cin, line);
    int n = line.size();
    for (int i = 0; i < n; ++i)
    {
        string s;
        while (line[i] == '6')
        {
            s += line[i];
            i++;
        }
        if (s.empty()) cout << line[i];
        else i--;
        if (s.size() > 3)
            s = s.size() < 10 ? "9" : "27";
        cout << s;
    }
}