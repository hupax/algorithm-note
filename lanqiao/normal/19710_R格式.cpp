//
// Created by hupax on 25-4-6.
//
#include <iostream>
#define gc getchar_unlocked()
using namespace std;
const int N=1028;
int n, a[N], p, k, q, res[N];
char c;
int main() {
    cin>>n; gc;
    p=1, k=0;
    c=gc; a[p]=c^48;
    while (c!='\n') {
        c=gc;
        a[++p]=c^48;
        if (c=='.') k=p--;
    }
    k=p-k;
    p--; q=p;
    for (int i=1; i<=p; i++) b[q--]=a[i];
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=p; j++) {
            res[j]+=b[j]*2;
            if (res[j]>=10) {
                res[j+1]+=res[j]/10;
                res[j]%=10;
            }
        }
    }
    while (res[p]>=10) {
        res[p+1]=res[p]/10;
        res[p]%=10;
        p++;
    }
    while (p>0&&res[p]==0) p--;
    while (p>k+1) cout<<res[p], p--;
    if (res[k+1]>4) cout<<res[k+1]+1;
    
    
    return 0;
}