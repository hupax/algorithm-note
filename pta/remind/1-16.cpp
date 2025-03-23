//
// Created by 沙枭 on 24-11-10.
//
#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int w[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6,
                 3, 7, 9, 10, 5, 8, 4, 2};
char m[11] = {'1', '0', 'X', '9', '8',
              '7', '6', '5', '4', '3', '2'};

int main() {
    int n;
    string line;
    cin >> n;
    int f = 1;
    while (n--) {
        cin >> line;
        int sum = 0;
        for (int i = 0; i <= 16; i++) {
            sum += w[i] * (line[i] - '0');
        }
        if (m[sum % 11] != line.back()) {
            cout << line << endl;
            f = 0;
        }
    }
    if (f) cout << "All passed" << endl;
    
}