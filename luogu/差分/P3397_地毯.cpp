//
// Created by hupax on 25-4-10.
//
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define inf INT_MAX
using namespace std;
const int N=1005;
int n, m, a[N][N];
int df[N][N];
int main() {
    cin>>n>>m;
    int lx, ly, rx, ry;
    for (int i=1; i<=m; i++) {
        cin>>lx>>ly>>rx>>ry;
        df[lx][ly]++;
        df[lx][ry+1]--;
        df[rx+1][ly]--;
        df[rx+1][ry+1]++;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+df[i][j];
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    
    return 0;
}