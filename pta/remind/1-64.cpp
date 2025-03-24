//
// Created by 沙枭 on 24-11-12.
//
//#include <bits/stdc++.h> AI
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int link;
string line, word, s;
int main() {
    cin >> link;
    cin.ignore();
    while (link--) {
        getline(cin, line);
//        cout << line << endl;
        cout << "AI: ";
        transform(line.begin(), line.end(), line.begin(), [] (char  c) {
          return (c == 'I') ? c : tolower(c);
        });
//        replace(line.begin(), line.end(), "can you", "I can");
        line.erase(unique(line.begin(), line.end(), [] (char a, char b) {
          return a == ' ' && b == ' ';
        }), line.end());
        int f = 0;
        while ((f = line.find("can", f) != -1)) {
            string s = line.substr(f - 1, 7);
//            cout << s << endl;
            if (s.substr(4) != "you") {
                f += 3;
                continue;
            }
            else if (isalpha(s[3])) {
                f += 3;
                continue;
            }
            line.replace(f, 7, "I can");
            f += 7;
        }
        f = 0;
        while ((f = line.find("could", f) != -1)) {
            string s = line.substr(f - 1, 9);
//            cout << s << endl;
            if (s.substr(6) != "you") {
                f += 5;
                continue;
            }
            else if (isalpha(s[5])) {
                f += 5;
                continue;
            }
            line.replace(f, 9, "I could");
            f += 9;
        }
        f = 0;
        replace(line.begin(), line.end(), '?', '!');
        istringstream iss(line);
        while (iss >> word) {
            if (f && isalpha(word[0])) cout << " ";
            if (word == "I" || word == "me") {
                cout << "you";
                f = 1;
            }
            f = 1;
            cout << word;
        }
        cout << endl;
    }
}
