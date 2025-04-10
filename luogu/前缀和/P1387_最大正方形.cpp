//
// Created by hupax on 25-4-10.
//
#include<bits/stdc++.h>
#define ll long long
#define fo(a, b, c) for (int a=b; a<=c; a++)
#define endl "\n"
#define pii pair<int, int>
using namespace std;
const int N=105;
int n, m, a[N][N];
int sum[N][N], ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    fo(i, 1, n) fo(j, 1, m) {
            cin >> a[i][j];
            sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+a[i][j];
        }
    
    int l=0, x, y; // 枚举正方形边长
    while (l < min(n, m)) {
        fo(i, l, n) fo(j, l, m) {
                x=l-i, y=j-l; // 左上角 l l 为右下角
                if (sum[i][j]-sum[i][y-1]-sum[x-1][j]+sum[x-1][y-1] >= l*l) {
                    ans=max(ans, l);
                }
            }
            l++;
    }
    cout << ans;
    
    return 0;
}