//
// Created by 沙枭 on 24-11-11.
//
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    string line;
    getline(cin, line, '\n');
    transform(line.begin(), line.end(), line.begin(), ::toupper);
    unordered_map<char, int> umap;
    for (char &c : line) {
        umap[c]++;
    }
    string s = "GPLT";
    while (true) {
        int f = 0;
        for (char &c : s) {
            if (umap[c]) {
                f--;
                umap[c]--;
                cout << c;
            }
        }
        if (!f) break;
    }
}
