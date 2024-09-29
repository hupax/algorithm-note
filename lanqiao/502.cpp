//
// Created by 沙枭 on 24-9-28.
//
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    double a = 0, b = 0, score;
    for (int i = 0; i < n; i++) {
        cin >> score;
        if (score >= 60) {
            a++;
        }
        if (score >= 85) {
            b++;
        }
    }
    cout << /*fixed <<*/ setprecision(2);
    cout << a / n * 100 << "%" << endl;
    cout << b / n * 100 << "%" << endl;
}