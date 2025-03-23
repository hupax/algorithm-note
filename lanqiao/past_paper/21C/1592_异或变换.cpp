//
// Created by supanx on 25-3-20.
//
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10005;

long long t;
int a[MAXN], b[MAXN], bin[MAXN], n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> t;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) a[i] = s[i]-'0';
    
    // 求所有 C(t, k) mod 2 == 1 的 k（利用Lucas定理）
    vector<int> comb_pos;
    for (int k = 0; k < n; k++) {
        if ((t & k) == k) comb_pos.push_back(k);  // 位不冲突说明C(t,k)%2==1
    }
    
    // 构造最终 b[i] = xor 所有 comb_pos 中 a[i - k]
    for (int i = 0; i < n; i++) {
        int val = 0;
        for (int k : comb_pos) {
            if (i-k >= 0) val ^= a[i-k];
        }
        b[i] = val;
    }
    
    for (int i = 0; i < n; i++) cout << b[i];
    cout << "\n";
    
    return 0;
}

// 0110
/*
5 3
10110
 
 11101
 
 1011
10110
 
 1101
 
 1110
11101
 0011
 
 10011
*/