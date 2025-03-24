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
    double link;
    while (cin >> link && link > 0 && link < 100)
    {
        char bi[2] = {'0', '1'};
        int d = (int)link;

        link -= d;

        vector<int> gg;
        while (d)
        {
            gg.push_back(d % 2);
            d /= 2;
        }
        for (int i = gg.size() - 1; i >= 0; --i) {
            cout << bi[gg[i]];
        }
        if (link)
        {
            cout << '.';
        }
        while (link)
        {
            link *= 2;
            cout << (int)link;
            link -= (int)link;
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