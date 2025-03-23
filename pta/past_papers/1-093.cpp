//
// Created by 沙枭 on 24-10-10.
//
// L1-093 猜帽子游戏

#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int n, k, gus;
    cin >> n;
    vector<int> hc(n);
    for (auto &i : hc) cin >> i;
    cin >> k;
    vector<string> ans = {"Ai Ya", "Da Jiang!!!"};
    while (k--) {
        int flag = 1;
        int zero = 0;
        for (int j = 0; j < n; j++) {
            cin >> gus;
            if (gus != hc[j] && gus) {
                flag = 0;
                break;
            }
            if (gus) zero++;
        }
        cout << ans[flag&&zero];
        if (k) cout << endl;
    }
    
}
/*
5
1 1 2 1 2
3
0 1 2 0 0
0 0 0 0 0
1 2 2 0 2

 */
