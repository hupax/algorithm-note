//
// Created by 沙枭 on 24-11-11.
//
#include <iomanip>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
int link, shm[1005], vis[1005], hh, mm, id;
char c, t;
int main() {
    cin >> link;
    while (link--) {
        memset(shm, 0, sizeof(shm));
        memset(vis, 0, sizeof(vis));
        int num = 0;
        double sum = 0;
        while (1) {
            cin >> id >> c >> hh >> t >> mm;
            if (!id) break;
            if (c == 'E' && !vis[id]) continue;
            if (c == 'S' && !vis[id]) {
                vis[id] = 1;
                shm[id] = hh * 60 + mm;
                continue;
            }
            num++;
            vis[id] = 0;
            sum += hh * 60 + mm - shm[id];
        }
        cout << num << " ";
        if (num) cout << round(sum / num * 1.0) << endl;
        else cout << 0 << endl;
    }
}