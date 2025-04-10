//
// Created by hupax on 25-4-10.
//
#include <bits/stdc++.h>
#define endl "\n"
#define gc getchar_unlocked()
using namespace std;
const int N=1e3+5;
char s[N], t[N], a=0, b=0;
int dp[N][N];
int main() {
    s[++a]=gc;
    while (s[a] != '\n') s[++a]=gc;
    a--;
    t[++b]=gc;
    while (t[b] != '\n') t[++b]=gc;
    b--;
    for (int i=1; i <= a; i++)
        for (int j=1; j <= b; j++) {
            dp[i][j]=s[i] == t[j] ? dp[i-1][j-1]+1 : max(dp[i-1][j], dp[i][j-1]);
        }
    cout << dp[a][b] << endl;
    return 0;
}
/*  A B C D E A B C D
A 1 1 1 1 1 1 1 1 1
A 1 1 1 1 1 2 2 2 2
B 1 2 2 2 2 2 3 3 3
Z 1 2 2 2 2 2 3 3 3
dp[i][j]=x : S 中前 i 个字符 和 T 中前 j 个字符
最长连续 x 个字符被 S 包含

dp[i][j]=?
1.....i-1, i
1.....j-1, j

i==j -> dp[i][j]=a+1
i!=j -> max(b, c)


1.dp[i-1][j-1]=a
 1.....i-1
 1.....j-1

2.dp[i][j-1]=b
 1.....i-1, i
 1.....j-1

3.dp[i-1][j]=c
 1.....i-1
 1.....j-1, j

*/

/*
#include <iostream>
#include <string>
using namespace std;

int longest_prefix_subsequence(const string &S, const string &T) {
    int n=S.size(), m=T.size();
    int i=0, j=0; // i指向S, j指向T
    int max_len=0;
    
    // 从T的第一个字符开始，尝试在S中匹配
    while (i < n && j < m) {
        if (S[i] == T[j]) {
            j++; // 找到一个字符匹配，T的指针向后移
            max_len++; // 增加连续匹配长度
        }
        i++; // S的指针向后移
    }
    
    // 如果j == m，说明T的所有字符都被匹配上了
    return max_len;
}

int main() {
    string S, T;
    cin >> S >> T; // 输入S和T
    int result=longest_prefix_subsequence(S, T);
    cout << result << endl; // 输出结果
    return 0;
}
*/
