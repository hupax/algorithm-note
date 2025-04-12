//
// Created by hupax on 25-4-11.
//
#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n, m[N][N], a, b, g, k;
int main() {
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>a>>b>>g>>k;
        for (int x=a; x<=a+g; x++) {
            for (int y=b; y<=b+k; y++) {
                m[x][y]=i;
            }
        }
    }
    cin>>a>>b;
    cout<<(m[a][b]?m[a][b]:-1);
    
    return 0;
}