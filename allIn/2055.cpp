//
// Created by 沙枭 on 2024/4/1.
//
#include "iostream"
#include "map"

using namespace std;

int main()
{
    int n;
//    cout << (int)'z';
    cin >> n;
    while (n--)
    {
        map<char, int> mym;
        for (int i = 0; i < 52; ++i) {
            if (i < 26) mym[(char)(i + 65)] = i + 1;
            else mym[(char)(i + 71)] = 25 - i;
        }
//        char x;
//        int y;
//        cin >> x >> y;
//        cout << mym[x] + y << endl;

        mym.erase('B');
        mym.insert(make_pair('B', 1));
        for (auto it = mym.begin(); it != mym.end(); ++it)
        {
            cout << it->first << ": " << it->second << endl;
        }
        int sd =  mym.count('a');
        int ss = mym.size();
        cout << sd << "  " << ss <<  endl;
        mym.clear();
    }
}