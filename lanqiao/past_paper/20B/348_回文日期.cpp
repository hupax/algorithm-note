//
// Created by hupax on 25-3-25.
//
#include <bits/stdc++.h>
using namespace std;
inline int check(int y) {
    return y%4==0&&y%100!=0||!y%400==0;
}
int ya, yb, m1, m2, d1, d2, sa[8], p;
inline void ensa(int k) {
    if (k==sa[p-1]) p--;
    else sa[p++]=k;
}
string s1, s2;
int main() {
    cin>>s1>>s2;
    ya=stoi(s1.substr(0, 4));
    yb=stoi(s2.substr(0, 4));
    m1=stoi(s1.substr(4, 2));
    m2=stoi(s2.substr(4, 2));
    d1=stoi(s1.substr(6));
    d2=stoi(s2.substr(6));
    int n;
    for (int i=ya+1; i<yb; i++) {
        p=0; n=i;
        while (n){
            sa[p++]=n%10;
            n/=10;
        }
        for (int j=1; j<=12; j++) {
            if (j<10)
        }
        
    }
    
    return 0;
}
