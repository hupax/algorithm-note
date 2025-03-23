//
// Created by supanx on 25-3-22.
//
// 数列中第 i 个元素之后第一个大于 ai的元素的下标
#include <iostream>
using namespace std;

const int maxn=3e6+5;
int n, a[maxn];
int s[maxn], hi=0, ans[maxn];
int main() {
    cin >> n;
    for (int i=1; i<=n; i++) scanf("%d", &a[i]);
    for (int i=n; i>0; i--) {
        while (hi&&a[i]>=a[s[hi-1]]) hi--;
        if (!hi) ans[i]=0;
        else ans[i]=s[hi-1];
        s[hi++]=i;
    }
    for (int i=1; i<=n; i++) cout << ans[i] << " ";
    return 0;
}