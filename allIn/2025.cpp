//
// Created by 沙枭 on 2024/3/28.
//
#include "iostream"
#include "string"

using namespace std;

int main()
{
    string line;
    while (cin >> line && line.length() <= 100)
    {
        char m = line[0];
        for (int i = 0; i < line.length(); ++i) {
            if (line[i] > m) m = line[i];
        }
        for (int i = 0; i < line.length(); ++i) {
            if (line[i] == m) cout << line[i] << "(m)";
            else cout << line[i];
        }
        cout << endl;
    }
    return 0;
}