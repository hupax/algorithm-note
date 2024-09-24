//
// Created by 沙枭 on 2024/4/5.
//
// L1-018 大笨钟
#include "iostream"
#include "string"

using namespace std;

int main()
{
    string line;
    while (cin >> line && line.empty() == 0)
    {
        int f = line.find(':');
        int hours = stoi(line.substr(0, f));
        int minute = stoi(line.substr(f + 1));
        if (minute != 0) hours++;
        if (hours > 12)
        {
            hours -= 12;
            for (int i = 0; i < hours; ++i) {
                cout << "Dang";
            }
            cout << endl;
        } else
        {
            cout << "Only " << line << ".  "
                    << "Too early to Dang." << endl;
        }
    }
}