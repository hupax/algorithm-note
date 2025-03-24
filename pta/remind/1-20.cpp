//
// Created by 沙枭 on 24-11-11.
//
#include <unordered_set>
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string id;
    unordered_set<string> uset;
    while (n--) {
        int k;
        cin >> k;
        if (k < 2) {
            cin >> id;
            continue;
        }
        while (k--) {
            cin >> id;
            uset.insert(id);
        }
    }
    cin >> n;
    int f = 1;
    while (n--) {
        cin >> id;
        if (uset.find(id) == uset.end()) {
            if (!f) cout << " ";
            cout << setw(5) << setfill('0') << id;
            f = 0;
            uset.insert(id);
        }
    }
    if (f) cout << "No one is handsome" << endl;
}