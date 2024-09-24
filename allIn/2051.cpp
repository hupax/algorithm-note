//
// Created by 沙枭 on 2024/4/1.
//
// Bitset
/*
#include "iostream"
#include "vector"

using namespace std;

int main()
{
    double n;
    while (cin >> n && n > 0 && n < 100)
    {
        char bi[2] = {'0', '1'};
        int d = (int)n;

        n -= d;

        vector<int> gg;
        while (d)
        {
            gg.push_back(d % 2);
            d /= 2;
        }
        for (int i = gg.size() - 1; i >= 0; --i) {
            cout << bi[gg[i]];
        }
        if (n)
        {
            cout << '.';
        }
        while (n)
        {
            n *= 2;
            cout << (int)n;
            n -= (int)n;
        }
        cout << endl;
        gg.clear();
    }
}
*/
#include "iostream"
#include "string"

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        string ans = "";
        while (n)
        {
            ans = to_string(n % 2) + ans;
            n /= 2;
        }
        cout << ans << endl;
    }
}