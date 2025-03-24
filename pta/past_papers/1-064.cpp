//
// Created by 沙枭 on 2024/4/11.
//
// L1-064 估值一亿的AI核心代码
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
#include <algorithm>
#include <list>
#include <string>
#include <cctype>

using namespace ::std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    string line;
    list<string> sl;
    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        cout << line << endl;
        replace(line.begin(), line.end(), '?', '!');
        istringstream iss(line);
        string word;
        while (iss >> word)
        {
            for (char &c : word)
                if (c != 'I') c = tolower(c);
//            transform(word.begin(), word.end(), word.begin(), ::toupper);
            sl.push_back(word);
        }
        for (auto it = sl.begin(); it != sl.end(); ++it) {
            if (it == sl.begin()) continue;
            auto pre = prev(it);
            if ((*pre == "can" || *pre == "could") && *it == "you") {
                *it = *pre == "can" ? "can" : "could";
                *pre = "I";
            }
            if ((*pre == "I" || *pre == "me") && (*it != "can" && *it != "could"))
                *pre = "you";
//            What Is this prime? I,don 't know
            if (!isalnum((*it)[0]))
            {
                *pre += *it;
                it = sl.erase(it);
            }
        }
        cout << "AI: ";
        for (auto it = sl.begin(); it != sl.end(); ++it)
        {
            if (it->size() > 1 && (*it)[0] == 'I' && !isalnum((*it)[1])) *it = "you" + it->substr(1);
            if (it != sl.begin()) cout << " ";
            cout << *it;
        }
        sl.clear();
        cout << endl;
    }
}