//
// Created by 沙枭 on 24-11-9.
//
#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, string> ba;
    map<string, string> bc;
    string id, ts, s;
    while (n--) {
        cin >> id >> ts >> s;
        ba[ts] = id;
        bc[ts] = s;
    }
    int m;
    cin >> m;
    while (m--) {
        cin >> ts;
        cout << ba[ts] << " " << bc[ts] << endl;
    }
}