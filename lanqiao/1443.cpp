//
// Created by 沙枭 on 24-9-29.
//
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    
    vector<int> cords(10, 2021);
    
    int n = 1;
    
    while (true) {
        int tmp = n;
        vector<int> need(10, 0);
        while (tmp) {
            int m = tmp % 10;
            need[m]++;
            tmp /= 10;
        }
        for (int i = 0; i < 10; i++) {
            if (need[i] > cords[i]) {
                return cout << n - 1 << endl, 0;
            }
//            cords[i] -= need[i];
        }
        for (int i = 0; i < 10; i++) {
            cords[i] -= need[i];
        }
        n++;
    }
    
}