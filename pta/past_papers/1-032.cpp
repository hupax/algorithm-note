//
// Created by 沙枭 on 2024/4/6.
//
// L1-032 Left-pad
#include "iostream"
#include "iomanip"

using namespace std;

int main()
{
    int n;
    char c;
    string line;
    cin >> n >> c;
    cin.ignore();
    getline(cin, line);
    int len = line.size();
    if (len <= n)
        cout << setw(n) << setfill(c) << line << endl;
    else
    {
        string subStr = line.substr(len - n);
        cout << subStr << endl;
    }
}