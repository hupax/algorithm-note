//
// Created by supanx on 25-3-18.
//
#include <iostream>
#include <vector>
using namespace std;
const int maxx = 1e6 + 5;


int l, cur, r;
string del(string s) {
    int n = s.size();
    if (n <= 2) return s;
    
    vector<int> vde(n);  // 删除字符的索引
    string ans;  // 剩余字符的索引
    ans.push_back(s[0]);
    
    for (int i = 1; i < n-1; i++) {
        l = i-1, cur = i, r = i+1;
        if (s[l] != s[cur] && s[cur] == s[r]) {
            if (!vde[l] && !ans.empty()) ans.pop_back();
            vde[l] = vde[cur] = 1;
        }
        else if (s[r] != s[cur] && s[cur] == s[l]) vde[cur] = vde[r] = 1;
        if (!vde[cur]) ans.push_back(s[cur]);
    }
    if (!vde[r]) ans.push_back(s.back());
    if (ans.empty()) return "EMPTY";
    if (ans.size() == n) return ans;
    return del(ans);
    
}
int main() {
    string s;
    cin >> s;
    cout << del(s);
    return 0;
}
//     1       1      1     1
// sd fh hhhc vhhx c xn nnnshh

// sdfhh h hc vhhxcxnnnnshh

// edda
// sdfhhhhcvhhxcxnnnnshh