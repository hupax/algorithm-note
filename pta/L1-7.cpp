//
// Created by 沙枭 on 2024/5/4.
//
// L1-7 撒狗粮
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, m, id;
unordered_map<int, int> cp;
unordered_map<int, int> ms;
vector<int> vs;
vector<int> vcp;
int main()
{
    cin >> n;
    vcp.resize(2 * n);
    for (int i = 1; i <= 2 * n; ++i)
    {
        cin >> id;
//        vcp.push_back(id);
        cp[id] = 1;
//        vcp.push_back(cp[id]);
    }
    cin >> m;
    vs.resize(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> vs[i];
        ms[vs[i]] = 0;
    }
    int g = 0;
    for (int i = 0; i < m; ++i)
    {
        if ()
    }
    
}
/*
4
11111 22222
33333 44444
55555 66666
77777 88888
10
11111 33333 88888 22222 23333 55555 66666 10000 44444 12345
 */