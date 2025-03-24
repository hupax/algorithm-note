//
// Created by supanx on 25-3-18.
//
#include <iostream>
#include <bitset>
#include <queue>
using namespace std;

const int maxn = 1e6+5;
char s[maxn];
bitset<maxn> removed, inq;

int n;

bool is_edge(int i) {
    if (removed[i]) return false;
    if (i > 0 && !removed[i-1] && s[i] == s[i-1]
        && (i+1 >= n || removed[i+1] || s[i] != s[i+1]))
        return true;
    if (i+1 < n && !removed[i+1] && s[i] == s[i+1]
        && (i == 0 || removed[i-1] || s[i] != s[i-1]))
        return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    while (s[n]) n++;
    
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (is_edge(i)) {
            q.push(i);
            inq[i] = 1;
        }
    }
    
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        if (removed[i]) continue;
        if (!is_edge(i)) continue;
        
        removed[i] = 1;
        
        if (i > 0 && !removed[i-1] && !inq[i-1]) q.push(i-1), inq[i-1] = 1;
        if (i+1 < n && !removed[i+1] && !inq[i+1]) q.push(i+1), inq[i+1] = 1;
    }
    
    bool empty = true;
    for (int i = 0; i < n; i++) {
        if (!removed[i]) cout << s[i], empty = false;
    }
    if (empty) cout << "EMPTY\n";
    return 0;
}


//     1       1      1     1
// sd fh hhhc vhhx c xn nnnshh

// sdfhh h hc vhhxcxnnnnshh

// edda
// sdfhhhhcvhhxcxnnnnshh