//
// Created by 沙枭 on 2024/4/6.
//
// L1-030 一帮一
#include "iostream"
#include "vector"
#include "string"

using namespace std;

int main()
{
    int n;
    vector<string> vector1;
    while (cin >> n && n > 0)
    {
        cin.ignore();
        for (int i = 0; i < n; ++i) {
            string line;
            getline(cin, line);
            vector1.push_back(line);
        }
        auto mid = vector1.begin() + vector1.size() / 2;
        for (auto i = vector1.begin(); i != mid; ++i)
        {
            for (auto t = vector1.rbegin(); t != vector1.rend(); ++t)
            {
                if (t[0] == "m") continue;
                if (i[0][0] != t[0][0])
                {
                    cout << i[0].substr(2) << " " << t[0].substr(2) << endl;
                    t[0] = "m";
                    break;
                }
            }
        }
    }
    vector1.clear();
}
/*

auto rMid = vector1.rend() - vector1.size() / 2;
*/