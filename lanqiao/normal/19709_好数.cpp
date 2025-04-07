//
// Created by hupax on 25-4-6.
//
#include <iostream>
using namespace std;

int n, ans=0;
inline int check(int x) {
    int pos=1, p;
    while (x) {
        p=x%10;
        if ((pos&1)&&!(p&1)||!(pos&1)&&(p&1)) return 0;
        pos++;
        x/=10;
    }
    return 1;
}
int main() {
    cin>>n;
    for (int i=1; i<=n; i++) if (check(i)) ans++;
    cout<<ans;
    
    return 0;
}