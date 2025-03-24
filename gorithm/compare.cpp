//
// Created by 沙枭 on 2024/4/17.
//
// L2-2 含茶量
#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

bool compare(pair<string, int> &a, pair<string, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

int main()
{
    int n;
    string id, line;
    map<string, int> msi;
    cin >> n;
    while (n--)
    {
        cin >> id;
        cin.ignore();
        getline(cin, line);
        int sum = 0;
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        istringstream iss(line);
        string word;
        while (iss >> word)
            if (word.substr(0, 7) == "chatgpt")
                sum++;
        msi[id] = msi[id] + sum;
    }
    vector<pair<string, int>> vep(msi.begin(), msi.end());
    sort(vep.begin(), vep.end(), compare);

    int i = 0;
    for (auto &pa : vep)
    {
        if (pa.second == 0) break;
        if (i < 3)
            cout << pa.first << " " << pa.second << endl;
        ++i;
    }
}