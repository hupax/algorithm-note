//
// Created by 沙枭 on 24-8-31.
//
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string name, id;
    int score, mins = 105, maxs = -1;
    cin >> n;
    string namef, namee, idf, ide;
    while (n--) {
        cin >> name >> id >> score;
        if (score > maxs) {
            namef = name;
            idf = id;
            maxs = score;
        }
        if (score < mins) {
            namee = name;
            ide = id;
            mins = score;
        }
//        cout << name << " " << id << " " << score << endl;
    }
    cout << namef << " " << idf << endl;
    cout << namee << " " << ide << endl;
}