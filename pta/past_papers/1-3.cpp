//
// Created by 沙枭 on 2024/4/4.
//
#include "iostream"
#include "string"
#include "map"

using namespace std;

int main()
{
    string line;
    while (cin >> line)
    {
        map<char, int> m;
        for (char c : line) {
            m[c] = m[c] + 1;
        }
        for (const auto &[key, value] : m)
        {
            cout << key << ":" << value << endl;
        }
    }
}