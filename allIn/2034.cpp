//
// Created by 沙枭 on 2024/3/30.
//
// 人见人爱A-B
#include "iostream"
#include "vector"

using namespace std;

int main()
{
    int n, m;
    while (cin >> n >> m && n > 0 && m > 0)
    {
        vector<int> setA(n);
        vector<int> setB(m);
        vector<int> re;
        for (int i = 0; i < n; ++i) {
            int t;
            cin >> t;
            setA.push_back(t);
        }
        for (int i = 0; i < m; ++i) {
            int t;
            cin >> t;
            setB.push_back(t);
        }

        bool gg = true;
        for (auto &i: setA)
        {
            bool f = true;
            for (auto &j: setB)
            {
                if (i == j) f = false;
            }
            if (f)
            {
                re.push_back(i);
                gg = false;
                continue;
            }
        }
        if (gg) cout << "NULL";
        sort(re.begin(), re.end());
        for (auto &item: re) cout << item << ' ';

//        cout << endl;

    }
}