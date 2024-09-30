//
// Created by 沙枭 on 24-9-30.
//
#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    ll a, b, n;
    cin >> a >> b >> n;
    
    ll weeks = n / (5 * a + 2 * b);
    
    ll need = n % (5 * a + 2 * b);
    
    ll ans = weeks * 7;
    
    int t = 1;
    while (need) {
        if (t % 7 == 7 || t % 7 == 0) need -= b;
        else need -= a;
        t++;
    }
    cout << ans + t << endl;
}
