//
// Created by hupax on 25-4-7.
//
#include <iostream>
#include <cmath>
using namespace std;

const int N=1e5+5;
int a[N];

int main() {
    int n;
    cin >> n;
    for (int i=1; i <= n; i++) cin >> a[i];
    
    int ans=0;
    for (int i=1; i <= n/2; i++) {
        ans+=abs(a[i]-a[n-i+1]);
    }
    cout << ans << endl;
    return 0;
}

