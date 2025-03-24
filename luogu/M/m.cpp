//
// Created by supanx on 25-3-22.
//
#include <bits/stdc++.h>
#define fo(i, a, b) for(int i=a;i<=b;++i)
#define ro(i, a, b) for(int i=a;i>=b;--i)
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
using namespace std;

int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = (x << 1)+(x << 3)+(ch^48);
        ch = getchar();
    }
    return x*f;
}

int main() {
    // 输入/主逻辑
    return 0;
}
