//
// Created by 沙枭 on 2024/4/4.
//
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define inf INT_MAX
#define pii pair<int, int>
#define fo(a, b) for (int i=a; i<=b; i++)
#define gc getchar_unlocked()
using namespace std;
void read(int &x) {
    int f=1;
    char ch=gc;
    while (!isdigit(ch)) {
        if (ch == '-') f*=-1;
        ch=gc;    }
    while (isdigit(ch)) {
        x=(x << 3)+(x << 1)+(ch^48);
        ch=gc;
    }
    x*=f;
}
const int N=1e3+5;

char s[N];
int n=0;
int dp[N][N];// s中 i...j 是回文长度
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    memset(dp, 0, sizeof(dp));
    s[++n]=gc;
    while (s[n] != '\n') s[++n]=gc;
    n--;
    
    fo(1, n) dp[i][i]=1;
    
    for (int len=2; len <= n; len++) {
        for (int i=1; i <= n-len+1; i++) {
            int j=i+len-1;
            if (s[i-1] == s[j-1]) dp[i][j]=dp[i+1][j-1]+2;
            else dp[i][j]=max(dp[i+1][j], dp[i][j-1]);
        }
    }
    cout << dp[n][n];
    
    return 0;
}