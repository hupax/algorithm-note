//
// Created by 沙枭 on 2024/3/29.
//
//如果一个字符串是回文串，则输出"yes",否则输出"no".

#include "iostream"
#include "string"
#include "algorithm"
#include "vector"

using namespace std;

int main()
{
    int n;
    while (cin >> n && n > 0)
    {
        cin.ignore();
        string line;
/*        auto * arr = new string [link];
        delete[] arr;*/
        vector<string> lines;
        for (int i = 0; i < n; ++i) {
            getline(cin, line);
            lines.push_back(line);
        }
        for (auto & l: lines)
        {
            string reline(l.length(),' ');
            reverse_copy(l.begin(), l.end(), reline.begin());
            if (l == reline) cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
}