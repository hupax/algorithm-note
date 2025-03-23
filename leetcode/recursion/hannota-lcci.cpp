//
// Created by supanx on 25-3-14.
//
#include <iostream>
#include <vector>
using namespace std;

void dfs(int x, vector<int> &s, vector<int> &e, vector<int> &h) {
    if (x == 1) {
        e.push_back(s.back());
        s.pop_back();
        return;
    }
    dfs(x - 1, s, h, e);
    e.push_back(s.back());
    s.pop_back();
    dfs(x - 1, h, e, s);
}
void hanota(vector<int> &A, vector<int> &B, vector<int> &C) {
    int x = A.size();
    dfs(x, A, C, B);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    vector<int> b, c;
    hanota(a, b, c);
    for (auto &i:c) cout << i << " ";
    
    return 0;
}