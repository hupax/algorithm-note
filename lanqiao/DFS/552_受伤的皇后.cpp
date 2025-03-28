//
// Created by hupax on 25-3-28.
//
#include <iostream>
using namespace std;
const int N=15;
int n, ans=0;
int col[N], pos[N]; // pos[i]=x 表示第i行皇后放在x列上
void dfs(int x) { // 搜索x行可以放的位置
    if (x==n+1) {
        ans++;
        return;
    }
    for (int i=1; i<=n; i++) { // 遍历每一列
        if (col[i]) continue;
        // 检查前两行
        int f=0;
        for (int k=1; k<3; k++) {
            if (x-k>0 && abs(pos[x-k]-i) == k) f=1; // 第一行不用检查
            // pos[x-k]上面第k行皇后的位置, 列差
        }
        if (f) continue;
        col[i]=1;
        pos[x]=i;
        dfs(x+1);
        col[i]=0;
    }
    
}
int main() {
    cin>>n;
    dfs(1);
    cout<<ans;
    
    return 0;
}
