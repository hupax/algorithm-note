//
// Created by 沙枭 on 2024/4/5.
//
/*#include "iostream"
#include "string"
#include "vector"

using namespace std;

int main()
{
    int n;
    while (cin >> n && n > 0)
    {
        vector<int> fM;
        vector<int> fZ;
        int gBeiS = 0;
        for (int i = 0; i < n; ++i) {
            string line;
            cin >> line;

            int step = line.find('/');
            if (step == -1) continue;
            string fz = line.substr(0, step);
            string fm = line.substr(step + 1);
            fZ.push_back(stoi(fz));
            fM.push_back(stoi(fm));
            if (gBeiS < stoi(fm)) gBeiS = stoi(fm);
        }
        while (1)
        {
            bool flag = true;
            for (auto t : fM) if (gBeiS % t != 0)
                {
                flag = false;
                    break;
                }
            if (flag) break;
            else gBeiS++;
        }
        int fZz = 0;
        for (int i = 0; i < n; ++i)
        {
            fZz += fZ[i] * (gBeiS / fM[i]);
        }

        int zShu = fZz / gBeiS;
        fZz %= gBeiS;

        int gYinS = fZz;
        while (gYinS > 1)
        {
            if (gBeiS % gYinS == 0 && fZz % gYinS == 0) break;
            else gYinS--;
        }

        if (zShu && fZz) cout << zShu << " " << fZz / gYinS << "/" << gBeiS / gYinS << endl;
        else if (zShu == 0 && fZz) cout << fZz / gYinS << "/" << gBeiS / gYinS << endl;
        else if (zShu && fZz == 0) cout << zShu << endl;
    }
}*/
#include "iostream"
#include "bits/stdc++.h"

using namespace std;
int n, a, b, up, down = 1;
char c;

int main() {
    cin >> n;
    while (n--) {
        cin >> a >> c >> b;
        up = up * b + a * down;
        cout << up << " " << endl;
        down *= b;
        int k = abs(gcd(up, down));
        up /= k;
        down /= k;
    }
    if (up % down == 0)cout << up / down << endl;
    else {
        if (up / down)cout << up / down << ' ';
        cout << up - up / down * down << '/' << down << endl;
    }
    return 0;
}
