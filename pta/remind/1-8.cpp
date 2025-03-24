//
// Created by 沙枭 on 24-11-10.
//
#include <iostream>
#include <iomanip>

using namespace std;

int main () {
    int a, b;
    cin >> a >> b;
    int sum = 0, f = 1;
    while (a <= b) {
        sum += a++;
        cout << setw(5) << a - 1;
        if (f++ % 5 == 0) cout << endl;
    }
    if ((f - 1) % 5 != 0) cout << endl;
    cout << "Sum = " << sum << endl;
}