//
// Created by hupax on 25-3-25.
//
#include <iostream>
using namespace std;
const int maxn=5e3+5;
int n, a[maxn], dp[maxn], ans=0;
int main() {
    cin>>n;
    for (int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
        dp[i]=1;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j < i; j++)
            if (a[i] > a[j]) dp[i]=max(dp[i], dp[j]+1);
        ans=max(ans, dp[i]);
    }
    cout<<ans;
    return 0;
}



/*
 *6
1 2 4 1 3 4

1 2
 * */