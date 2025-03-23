//
// Created by supanx on 25-3-20.
//
#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int> &height) {
    const int maxn = 2e4+5;
    int siz = height.size();
    int lh[maxn], rh[maxn];
    lh[0] = height[0], rh[siz-1] = height[siz-1];
    for (int i = 1; i < siz; i++) {
        lh[i] = max(lh[i-1], height[i]);
    }
    for (int i = siz-2; i >= 0; --i) {
        rh[i] = max(rh[i+1], height[i]);
    }
    for (int i = 0; i < siz; ++i) {
        cout << lh[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < siz; ++i) {
        cout << rh[i] << " ";
    }
    return 0;
}
/*[4,2,0,3,2,5]
 * int trap(vector<int>& height) {
    int siz = height.size();
    if (siz == 0) return 0;

    vector<int> lh(siz), rh(siz);
    lh[0] = height[0];
    rh[siz - 1] = height[siz - 1];

    for (int i = 1; i < siz; ++i)
        lh[i] = max(lh[i - 1], height[i]);
    for (int i = siz - 2; i >= 0; --i)
        rh[i] = max(rh[i + 1], height[i]);

    // debug打印
    for (int i = 0; i < siz; ++i) cout << lh[i] << ' ';
    cout << '\n';
    for (int i = 0; i < siz; ++i) cout << rh[i] << ' ';
    cout << '\n';

    int res = 0;
    for (int i = 0; i < siz; ++i)
        res += min(lh[i], rh[i]) - height[i];
    return res;
}
*/
int main() {
    vector<int> v;
    int a;
    char c;
    while (cin >> c && c != ']') {
        cin >> a;
        v.push_back(a);
    }
    trap(v);
    return 0;
}