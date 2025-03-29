//
// Created by hupax on 25-3-29.
//
#include <iostream>
#define foi(a, b) for (int i=a; i<=b; i++)
#define foj(a, b) for (int j=a; j<=b; j++)
#define gc getchar_unlocked()
using namespace std;
const int mod=1e9+7;
const int N=5e3+5;
char s[N];
int n=1, dp[N][N]; // dp[i][j] 表示前i个位置,j个左括号未匹配的方案数
int main() {
    s[n]=gc;
    while (s[n]!='\n')s[++n]=gc;
    --n;
    dp[1][0]=1;
    foi(1, n) { // 每个位置
        foj(0, n) { // 前i个位置,j个左括号未匹配
            // 插入左括号
            if (j>=1) dp[i][j]=dp[i][j-1]+1;
            if ()
        }
    }
    
    return 0;
}