//
// Created by hupax on 25-4-5.
//
#include <iostream>
using namespace std;
int a[11];
int dp(int n) {
    if (n<2022) return 0;
    int k=0;
    while (n>0) {
        a[++k]=n%10;
        n/=10;
    }
    
    
}
int l, r;
int main() {
    cin>>l>>r;
    cout<<dp(l)-dp(r);
    
    
    return 0;
}