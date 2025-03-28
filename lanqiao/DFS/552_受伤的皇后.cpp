//
// Created by hupax on 25-3-28.
//
#include <iostream>
using namespace std;
const int N=15;
int n, a[N][N], ans;
int row[N], col[N], dig1[N], dig2[N];
void dfs(int x, int cnt) { // 搜索x行可以放的位置
    if (x==n) {
        if (cnt==n) ans++;
        return;
    }
    for (int i=1; i<=n; i++) { // 遍历每一列
        if (col[i]) continue;
        if ((x-dig1[x+i]<3 || x-dig2[x-i+n]<3)) continue; // 在同一个对角线
        dig1[x+i]=dig2[x-i+n]=x;
        col[i]=1;
        dfs(x+1, cnt+1);
        dig1[x+1]=dig2[x-i+n]=col[i]=0;
    }
    
}
int main() {
    cin>>n;
    dfs(1, 0);
    cout<<ans;
    
    return 0;
}
