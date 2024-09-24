//
// Created by 沙枭 on 2024/4/17.
//
// 1109 擅长C
// Created on 2024/04/17
#include <bits/stdc++.h>
#include <iostream>
#include <map>

using namespace std;

int main()
{

    map<char, vector<string>> mcs;
    string st;
    for (int i = 0; i < 26; ++i)
    {
        vector<string> vs(7);
        for (int j = 0; j < 7; ++j)
            cin >> vs[j];
        mcs[(char)(65 + i)] = vs;
    }
    string words;
    cin >> words;
    vector<string> vs;
    while (!words.empty())
    {
        string s = "";
        for (char c : words)
        {
            if (isalpha(c) && isupper(c))
                s += c;
            else break;
        }
        vs.push_back(s);
        words.erase(0, s.size() + 1);
    }
    for (string s : vs)
    {
        for (int i = 0; i < 7; ++i)
        {
            for (char c : s)
            {
                if (c != s.front()) cout << " ";
                cout << mcs[c][i];
            }
            cout << endl;
        }
        cout << endl;
    }
}