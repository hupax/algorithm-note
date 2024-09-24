//
// Created by 沙枭 on 2024/3/28.
//
#include "iostream"

using namespace std;

int main() {
    int n;
    while (cin >> n && n > 0) {
        auto* v = new int[n];
        int m;
        for (int i = 0; i < n; ++i) {
            cin >> m;
            v[i] = m;
        }
//        auto minn = min_element(v.begin(), v.end());
//        int min = *minn;
        int min = v[0];
        for (int i = 0; i < n; ++i) {
            if (v[i] < min)
            {
                min = v[i];
            }
        }
        int t = 0;
        for (int i = 0; i < n; ++i) {
            if (v[i] == min)
            {
                t = v[i];
                v[i] = v[0];
                v[0] = t;
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << v[i] << ' ';
        }
        cout << endl;
        delete[] v;
    }
}
