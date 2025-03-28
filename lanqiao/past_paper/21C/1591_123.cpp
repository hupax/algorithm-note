//
// Created by supanx on 25-3-22.
//
#include <iostream>
using namespace std;
using ll=long long;
const int N=1e5+5;
int n;
ll l, r;
inline ll check(ll p) {
    ll k=1;
    while (k*(k+1)/2+1<p) {
        k++;
    }
    return k;
}
int main() {
    cin>>n;
    while (n--) {
        cin>>l>>r;
        ll ans=0;
        ll lp=check(l), rp=check(r);
        ll sl=(lp-1)*lp/2+1;
        if (lp==rp) {
            ans+=((r-sl)*(r-sl+1)-(l-sl)*(l-sl+1))/2;
        }
        else {
            ans+=lp*(lp+1)/2-(l-sl)*(l-sl+1)/2;
            while (lp-rp>1) {
                lp++;
                ans+=lp*(lp+1)/2;
            }
            ll sr=(rp-1)*rp/2;
            ans+=(r-sr)*(r-sr+1)/2;
        }
        if (!ans) ans++;
        cout<<ans<<endl;
        
    }
//    int a=check(5), b=check(6);
//    int c=(a-1)*a/2+1;
//    cout<<a<<" "<<c<<" "<<b;
    
    
    
    return 0;
}