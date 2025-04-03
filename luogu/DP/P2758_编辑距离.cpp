//
// Created by hupax on 25-3-31.
// jy
#include <iostream>
#include <string>
#define foi(a, b) for (int i=a; i<=b; i++)
#define foj(a, b) for (int j=a; j<=b; j++)
#define gc getchar_unlocked()
using namespace std;
const int N=2e3+5;

char a[N], b[N];
/*
 * dp[i][j]: A:1...i --> B:1...j 最少操作次数
 * init: dp[i][0]=i, dp[0][j]=j
 *
 */
int n=1, m=1, dp[N][N];
int main() {
    a[n]=gc;
    while (a[n]!='\n') a[++n]=gc;
    b[m]=gc;
    while (b[m]!='\n') b[++m]=gc;
    --n, --m;
    foi(1, n) dp[i][0]=i;
    foi(1, m) dp[0][i]=i;
    
    foi(1, n) foj(1, m) {
        if (a[i]==b[j]) dp[i][j]=dp[i-1][j-1];
        else dp[i][j]=min(min(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j])+1;
    }
    cout<<dp[n][m];
    
    return 0;
}

/*
 dp[i][j]=?
 
 A: 1...i-1, i
 
 B: 1...j-1, j
 
 1.i j a[i]==b[j]: dp[i][j]=dp[i-1][j-1];
 2.j dp[i][j]=dp[i][j-1]+1;
 3.i dp[i][j]=dp[i-1][j]+1;
 
 1
 dp[i-1][j-1]=a;
 A: 1...i-1
 B: 1...j-1
 2
 dp[i][j-1]=b;
 A: 1...i
 B: 1...j-1
 3
 dp[i-1][j]=c;
 A: 1...i-1
 B: 1...j
 
 */