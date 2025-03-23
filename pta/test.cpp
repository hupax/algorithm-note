//
// Created by 沙枭 on 2024/4/4.
//
#include "vector"
#include <iostream>
#include <sstream>
#include <string>
#include "cstddef"
#include "cstdlib"
#include "cmath"
#include "iomanip"
#include "map"
#include "algorithm"
#include "numeric"
#include "bits/stdc++.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

include<iostream>
include<string>
using namespace std;
string line;
int main() {
    cin >> line;
    cout << "year:" << line.substr(0, 4) << endl;
    cout << "department:" << line.substr(4, 2) << endl;
    cout << "class:" << line.substr(6, 4) << endl;
    
}
/*
6
2 6 4
1 0 0
3 1
2 0 5
3 0
1 0 2
1
01100

00000
11100
10011
01100


6
2 6 4
1 0 0
3 1
2 0 0
3 0
1 5 2
1
01100

 */
/*int wua(vector<edge> &v, int h)
{
    if (h < 0) return 0;
    if (v[h].left == 0 || (v[h].right == 0 && v[h].data != 3))
    {
        if (v[h].data == 3)
        {
            if (v[h].lam == '1')
                v[h].am = 0;
            else v[h].am = 1;
        }
        else if (v[h].data == 1)
        {
            if (v[h].lam == '0' || v[h].ram == '0')
                v[h].am = 0;
            else v[h].am = 1;
        }
        else
        {
            if (v[h].lam == '1' || v[h].ram == '1')
                v[h].am = 1;
            else v[h].am = 0;
        }
        return v[h].am;
    }
    else
    {
        int la = wua(v, v[h].left - 1);
        int ra = wua(v, v[h].right - 1);
        if (v[h].data == 3)
        {
            if (la == 1)
                v[h].am = 0;
            else v[h].am = 1;
        }
        else if (v[h].data == 1)
        {
            if (la == 0 || ra == 0)
                v[h].am = 0;
            else v[h].am = 1;
        }
        else
        {
            if (la == 1 || ra == 1)
                v[h].am = 1;
            else v[h].am = 0;
        }
        return v[h].am;
    }
}*/
/*void assi(vector<edge> &v, int h)
{
    if (h < 0) return;
    assi(v, v[h].left - 1);
    assi(v, v[h].right - 1);

    if (v[h].left == 0 || (v[h].right == 0 && v[h].data != 3))
    {
        wua(v[h]);
        return;
    }

    v[h].lam = v[v[h].left - 1].am;
    v[h].ram = v[v[h].right - 1].am;
    wua(v[h]);
}*/