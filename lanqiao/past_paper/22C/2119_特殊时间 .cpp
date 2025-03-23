//
// Created by supanx on 25-3-19.
//
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int f3, f1;
void isans1(string ss) {
    int cnt[10] = {0};
    for (auto &s : ss) cnt[s-'0']++;
    f3 = -1, f1 = -1;
    for (int i = 0; i < 10; i++) {
        if (cnt[i] == 3) f3 = i;
        else if (cnt[i] == 1) f1 = i;
        else if (cnt[i] != 0) return;
    }
}
string tos(int k, int l) {
    string s1 = to_string(k);
    while (s1.size() < l) {
        s1 = '0' + s1;
    }
    return s1;
}
int dd[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int days(int y, int m) {
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0) && m == 2) return 29;
    return dd[m];
}
int main() {
    int ans = 0;
    for (int y = 1; y <= 9899; y++) {
        string ys = tos(y, 4);
        isans1(ys);
        if (f3 == -1 || f1 == -1) continue;
        int y3 = f3, y1 = f1;
        for (int m = 1; m <= 12; m++) {
            string ms = tos(m, 2);
            int md = days(y, m);
            for (int d = 1; d <= md; d++) {
                string mds = ms + tos(d, 2);
                isans1(mds);
                int md3 = f3, md1 = f1;
                if (f3 == -1 || f1 == -1 || (md3 != y3 || md1 != y1)) continue;
                for (int h = 0; h <= 23; h++) {
                    string hs = tos(h, 2);
                    for (int mi = 0; mi <= 59; mi++) {
                        string mhs = hs +tos(mi, 2);
                        isans1(mhs);
                        int mhs3 = f3, mhs1 = f1;
                        if (f3 == -1 || f1 == -1 || (mhs3 != y3 || mhs1 != y1)) continue;
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans;
    
    return 0;
}