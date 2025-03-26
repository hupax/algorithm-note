//
// Created by hupax on 25-3-25.
//
#include <bits/stdc++.h>
using namespace std;
int longestCommonSubsequence(string text1, string text2) {
    int dp[1005][1005];
    memset(dp, 0, sizeof(dp));
    text1 = '0'+text1;
    text2 = '0'+text2;
    for (int i=1; i<text1.size(); i++) {
        for (int j=1; j<text2.size(); j++) {
            if (text1[i]==text2[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[text1.size()-1][text2.size()-1];
}