//
// Created by supanx on 25-3-18.
//
#include <iostream>
#include <bitset>
using namespace std;
const int maxx = 18;
int n, map[maxx][maxx];
bitset<maxx> col, dlg1, dlg2; // 列, 对角线1, 对角线2
int ans, pos[maxx], flag = 0; // flag标记输出前三个解
void dfs(int row, int cur) {
    if (row == n + 1) {
        if (cur == n + 1) {
            for (int i = 1; flag < 3 && i < cur; i++) {
                cout << pos[i] << " ";
            }
            flag++;
            if (flag <= 3) cout << endl;
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (col[i] || dlg1[row + i] || dlg2[row - i + n]) {
            continue;
        }
        col[i] = dlg1[row + i] = dlg2[row - i + n] = 1;
        pos[cur] = i;
        dfs(row + 1, cur + 1);
        col[i] = dlg1[row + i] = dlg2[row - i + n] = 0;
    }
    
}
int main() {
    scanf("%d", &n);
    dfs(1, 1);
    cout << flag;
    return 0;
}
/*
2 4 6 1 3 5
3 6 2 5 1 4
4 1 5 2 6 3
4
*/