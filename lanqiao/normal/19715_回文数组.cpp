//
// Created by hupax on 25-4-7.
//
#include <iostream>
using namespace std;
const int N=1e5+5;
int n, a[N], df[N];
int ans=0;
int main() {
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    for (int i=1; i<=n/2; i++) df[i]=a[n-i+1]-a[i];
    for (int i=1; i<=n/2; i++) {
        if (df[i]>0 && df[i+1]>0) {
            if (df[i]<df[i+1]) {
                ans+=df[i];
                i++;
            }
            else {
                ans+=df[i];
                df[i+1]-=df[i];
            }
        }
        else if (df[i]<0 && df[i+1]<0) {
            if (df[i]<df[i+1]) {
                ans+=-df[i];
                i++;
            }
            else {
                ans+=-df[i];
                df[i+1]-=df[i];
            }
        }
        else ans+=abs(df[i]);
    }
    cout<<ans;
    
    return 0;
}

