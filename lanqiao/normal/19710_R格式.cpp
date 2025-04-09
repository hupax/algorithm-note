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
    for (int i=1; i<=p; i++) res[q--]=a[i];
    
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=p; j++) res[j]<<=1;
        
        for (int j=1; j <= p; j++) {
            if (res[j]>=10) {
                res[j+1]+=res[j]/10;
                res[j]%=10;
            }
        }
        while (res[p+1]) p++;
    }
    if (res[k]>=5) {
        res[k+1]++;
        for (int i=k+1; i<=p; i++)
            if (res[i] >= 10) {
                res[i+1]+=res[i]/10;
                res[i]%=10;
            }
        if (res[p+1]) p++;
    }
    if (p==k) cout<<0;
    else while (p>k) cout<<res[p--];
    
    
    return 0;
}