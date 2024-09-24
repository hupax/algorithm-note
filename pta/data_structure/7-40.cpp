//
// Created by 沙枭 on 24-5-21.
//
// 7-40 奥运排行榜
#include <iostream>
#include <vector>
using namespace std;
int n, m;
struct node
{
  int gold;
  int total;
  int man;
};
void Foo(const vector<node> &ans);
int main()
{
    cin >> n >> m;
    vector<node> ans(n);
    for (int i = 0; i < n; ++i) {
        cin >> ans[i].gold >> ans[i].total >> ans[i].man;
    }
    for (int i = 0; i < m; ++i) {
    
    }
}
void Foo(const vector<node> &ans)
{
}
/*
输出格式:
在一行里顺序输出前来咨询的国家的排名:计算方式编号。其排名按照对该国家最有利的方式计算；
 计算方式编号为：金牌榜=1，奖牌榜=2，国民人均金牌榜=3，国民人均奖牌榜=4。
 输出间以空格分隔，输出结尾不能有多余空格。
若某国在不同排名方式下有相同名次，则输出编号最小的计算方式。
输入样例:
4 4
51 100 1000
36 110 300
6 14 32
5 18 40
0 1 2 3
输出样例:
1:1 1:2 1:3 1:4
 
 */