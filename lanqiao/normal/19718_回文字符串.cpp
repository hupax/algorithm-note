//
// Created by hupax on 25-4-6.
//
#include <bits/stdc++.h>
#define gc getchar_unlocked()
using namespace std;
const int S=1e6+5;
int n, p=1, f[150], ans;
char c[S];
int main() {
    cin>>n;gc;
    f['l']=f['q']=f['b']=1;
    while (n--) {
        p=1;ans=1;c[p]=gc;
        while (c[p]!='\n') c[++p]=gc;--p;
        while (f[c[p]]) --p;
        int l=1, r=p;
        while (l<r) {
            if (c[l]!=c[r]) {
                ans=0;
                break;
            }
            l++, r--;
        }
        if (ans) cout<<"Yes\n";
        else cout<<"No\n";
    }
    
    return 0;
}