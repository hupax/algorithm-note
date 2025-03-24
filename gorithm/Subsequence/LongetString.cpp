//
// Created by 沙枭 on 24-5-8.
//

#include <iostream>
#include <set>
#include <string>
using namespace std;
const int M = 105;

string line1, line2;
// 最长公共子字符串LIS
int mLen, mIndex, dp[M][M];
// 最长公共子序列LCS
int ans, vis[M][M];
set<string> allLcs;
//string lcs = "";
void findAllLcs(int i, int j, string lcs, set<string> &setLcs)
{
    while (i > 0 && j > 0)
    {
        if (line1[i] == line2[j])
        {
            lcs = line1[i] + lcs;
            i--;
            j--;
        }
        else if (vis[i - 1][j] > vis[i][j - 1])
        {
            i--;
        }
        else if (vis[i - 1][j] == vis[i][j - 1])
        {
            findAllLcs(i - 1, j, lcs, setLcs);
            findAllLcs(i, j - 1, lcs, setLcs);
            return; // return是关键
        }
        else j--;
    }
    if (!lcs.empty())
        setLcs.insert(lcs);
}
int main()
{
    
    cin >> line1 >> line2;
    int l1 = line1.size();
    int l2 = line2.size();
    line1 = ' ' + line1;
    line2 = ' ' + line2;
    for (int i = 1; i <= l1; ++i)
    {
        for (int j = 1; j <= l2; ++j)
        {
            if (line2[j] == line1[i])
            {
                // 最长公共子字符串
                dp[i][j] = dp[i - 1][j - 1] + 1;  // 左上角
                // 最长公共子序列
                vis[i][j] = vis[i - 1][j - 1] + 1;
            }
            else
            {
                // 最长公共子字符串LIS
                dp[i][j] = 0;
                // 最长公共子序列LCS
                vis[i][j] = max(vis[i - 1][j], vis[i][j - 1]);  // 左边和上边取大
            }
            // 最长公共子字符串LIS
            if (mLen < dp[i][j])
            {
                mLen = dp[i][j];
                mIndex = j;
            }
        }
    }
    // 最长公共子字符串LIS
    cout << "LIS: " << mLen << " ";
    cout << line2.substr(mIndex - mLen + 1, mLen) << endl;
    
    // 最长公共子序列LCS
    cout << "LCS: " << vis[l1][l2] << " ";
    findAllLcs(l1, l2, "", allLcs);
    for (auto &s : allLcs)
        cout << s << " ";
    cout << endl;
    // 回溯重构LCS,有缺陷,不能找出所有的LCS;
/*    int i = l1, j = l2;
    while (i > 0 && j > 0)
    {
        if (line1[i] == line2[j])
        {
            lcs = line1[i] + lcs;
            i--;
            j--;
        }
        else if (vis[i - 1][j] > vis[i][j - 1])
            i--;
        else j--;
    }
    // 最长公共子序列LCS
    cout << "LCS: " << vis[l1][l2] << " ";
    cout << lcs << endl;*/
}
