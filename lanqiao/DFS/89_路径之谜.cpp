//
// Created by hupax on 25-3-25.
//
#include <iostream>
using namespace std;
const int maxn=25;
int n, a[maxn], b[maxn];
int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};
int ans[maxn];
void dfs(int idx, int x, int y) {
    if (idx==n-1) {
        int f=1;
        for (int i=1; i<=n; i++) if (a[i]) f=0;
        for (int i=1; i<=n; i++) if (b[i]) f=0;
        if (f) ;
        return;
    }
    

}
int main() {
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    for (int i=1; i<=n; i++) cin>>b[i];
    
    return 0;
}