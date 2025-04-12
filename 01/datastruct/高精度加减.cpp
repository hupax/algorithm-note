//
// Created by supanx on 25-3-7.
//
/*
 * 高精度运算(加减乘除)
 *
 *//*
#include <iostream>
#include <string>
using namespace std;
const int maxs = 505;
// add
string s;
int la, lb, lc, a[maxs], b[maxs], c[maxs];

int init1(int k[]) {
    cin >> s;
    int l = s.size();
    for (int i = 0; i < l; i++) {
        k[i] = s[l - i - 1] - '0';
    }
    return l;
}
int main() {
    la = init1(a);
    lb = init1(b);
    lc = max(la, lb) + 1;
    for (int i = 0; i < lc; i++) {
        c[i] += a[i] + b[i];
        if (c[i] >= 10) {
            c[i] -= 10;
            c[i + 1]++;
        }
    }
    while (c[lc] == 0 && lc>0) {
        lc--;
    }
    while (lc >= 0) {
        cout << c[lc--];
    }
    
    return 0;
}
*/

/*
 * 1001
   9099*/


#include <iostream>
#include <string>
using namespace std;
const int maxs = 10090;
string s1, s2;
int la, lb, lc, a[maxs], b[maxs], c[maxs];
// sub
int init1(int k[], string s) {
    int l = s.size();
    for (int i = 0; i < l; i++) k[i] = s[l - i - 1] - '0';
    
    return l;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // "ac" "abc"
    cin >> s1 >> s2;
    if (s1.size() < s2.size() || (s1.size() == s2.size() && s1 < s2)) {
        cout << '-';
        swap(s1, s2);
    }
    la = init1(a, s1);
    lb = init1(b, s2);
    lc = max(la, lb);
    for (int i = 0; i < lc; i++) {
        c[i] += a[i] - b[i];
        if (c[i] < 0) {
            c[i] += 10;
            c[i + 1]--;
        }
    }
    while (c[lc] == 0 && lc > 0) lc--;
    while (lc >= 0) cout << c[lc--];
    
    return 0;
}
