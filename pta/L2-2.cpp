//
// Created by 沙枭 on 2024/5/1.
//
// L2-2 含茶量
#include <iostream>
#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
bool cmp(pair<string, int> &a, pair<string, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    else return a.second > b.second;
}
int main()
{
    int n;
    string id, line;
    cin >> n;
    unordered_map<string, int> a;
    while (n--)
    {
        cin >> id;
        cin.ignore();
        getline(cin, line);
        auto it = line.begin();
        transform(it, line.end(), it, ::tolower);
        int sum = 0;
        int f = line.find("chatgpt");
        while (f != -1)
        {
            sum++;
            line.erase(f, 7);
            f = line.find("chatgpt");
        }
        if (sum)
        {
            a[id] += sum;
        }
    }
    vector<pair<string, int>> vp(a.begin(), a.end());
    sort(vp.begin(), vp.end(), cmp);
    for (auto &p : vp)
    {
        cout << p.first << " " << p.second << endl;
        n++;
        if (n == 2) break;
    }

}
