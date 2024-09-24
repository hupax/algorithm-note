//
// Created by 沙枭 on 2024/4/6.
//
// L1-025 正整数A+B
#include "iostream"
#include "string"

using namespace std;

int main()
{
    string line;
    getline(cin, line);
    string a = line.substr(0, line.find(' '));
    string b = line.substr(line.find(' ') + 1);
    bool aA = true;
    bool bB = true;
    for (char i : a) if (isdigit(i) == 0) aA = false;
    for (char i : b) if (isdigit(i) == 0) bB = false;

    if (aA && (stoi(a) < 1 || stoi(a) > 1000)) aA = false;
    if (bB && (stoi(b) < 1 || stoi(b) > 1000)) bB = false;
    if (!aA) a = "?";
    if (!bB) b = "?";
    if (aA && bB) cout << stoi(a) << " + " << stoi(b) <<
                    " = " << stoi(a) + stoi(b) << endl;
    else cout << a << " + " << b << " = " << "?" << endl;
}