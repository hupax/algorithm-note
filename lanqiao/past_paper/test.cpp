#include <iostream>
using namespace std;

const int N=15;
int n, ans;
bool vis[N]; // 记录列是否被占用
int pos[N];  // pos[i] 表示第 i 行的皇后放在 pos[i] 列

void dfs(int i) {
    if (i == n) {
        ans++;
        return;
    }
    for (int j=0; j < n; ++j) { // 枚举行 i 放在哪一列
        if (vis[j]) continue; // 列冲突
        // 检查和前两行的对角线限制
        bool ok=true;
        for (int k=1; k <= 2; ++k) {
            if (i-k >= 0) {
                if (abs(pos[i-k]-j) == k) {
                    ok=false;
                    break;
                }
            }
        }
        if (!ok) continue;
        vis[j]=true;
        pos[i]=j;
        dfs(i+1);
        vis[j]=false;
    }
}
int a[5]={-1};
int main() {
    for (int &i:a) cout << i;
}
