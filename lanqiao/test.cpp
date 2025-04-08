#include <bits/stdc++.h>
using namespace std;
const int N=25;
int n, best=1e9;
double m, a[N];

void dfs(int i, double sum, int cuts) {
    if (sum > m+1e-6 || cuts >= best) return;
    if (abs(sum-m) < 1e-6) {
        best=cuts;
        return;
    }
    if (i == n) return;
    
    // 不选当前瓜
    dfs(i+1, sum, cuts);
    
    // 直接用整瓜
    dfs(i+1, sum+a[i], cuts);
    
    // 切一刀，使用一个半瓜
    dfs(i+1, sum+a[i]/2, cuts+1);
    
    // 切一刀，使用两个半瓜
    dfs(i+1, sum+a[i], cuts+1);
}

int main() {
    cin >> n >> m;
    for (int i=0; i < n; i++) cin >> a[i];
    
    dfs(0, 0, 0);
    
    cout << (best == 1e9 ? -1 : best) << endl;
    return 0;
}
