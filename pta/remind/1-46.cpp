//
// Created by 沙枭 on 24-11-12.
//
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int num = 0, curr = 0, f = 0;
    while (num++) {
        curr = (curr << 3) + (curr << 1) + 1;
        if (curr >= n) {
            f = 1;
            cout << curr / n;
        }
        else if (f) cout << 0;
        curr %= n;
        if (!curr) break;;
    }
    cout << " " << num << endl;
}