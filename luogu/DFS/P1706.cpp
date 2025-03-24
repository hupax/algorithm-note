//
// Created by supanx on 25-3-13.
//
#include <iostream>
using namespace std;
/*
 * 构建搜索树
 *
 */
const int maxx = 15;
int n;
int f[maxx]; // 标记数组 f[i] = 0, 表示序列中 i 还未使用
int ans[maxx]; // 答案
void dfs(int k) {
    if (k > n) {
        for (int i = 1; i <= n; i++) {
            printf("%5d", ans[i]);
        }
        cout<<endl;
        cout.flush();
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!f[i]) {
            ans[k] = i;
            f[i] = 1;
            dfs(k+1);
            f[i] = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>n;
    dfs(1);
    
    return 0;
}