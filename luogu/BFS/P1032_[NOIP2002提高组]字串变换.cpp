//
// Created by hupax on 25-3-26.
//
#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;
struct ru {
  string x, to;
};
int n=1;
string a, b, x[100], y[100];
queue<string> q;
unordered_set<string> vis;
int main() {
    cin>>a>>b;
    while (cin>>x[n]>>y[n]) n++; n--;
    q.push(a);
    vis.insert(a);
    int siz;
    for (int i=1; i<=10; i++) {
        siz=q.size();
        while (siz--) {
            string st=q.front(); q.pop();
            if (st==b) {
                cout << i; return 0;
            }
            for (int j=1; j<=n; j++) {
                int pos=0;
                while ((pos=st.find(x[i], pos))!=-1) {
                    string nw=st.substr(0, pos)+y[i]+st.substr(pos+x[i].size());
                    if (vis.count(nw)) continue;
                    vis.insert(nw);
                    q.push(nw);
                    pos+=x[i].size();
                }
                
            }
        }
    }
    cout<<"NO ANSWER";
    
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

const int MAX_DEPTH = 10;
string A, B;
vector<pair<string, string>> rules;
unordered_set<string> vis;

int bfs() {
    queue<pair<string, int>> q;
    q.push({A, 0});
    vis.insert(A);

    while (!q.empty()) {
        auto [s, d] = q.front(); q.pop();
        if (d > MAX_DEPTH) break;
        if (s == B) return d;

        for (auto& [from, to] : rules) {
            for (int i = 0; i + from.size() <= s.size(); ++i) {
                if (s.substr(i, from.size()) == from) {
                    string t = s.substr(0, i) + to + s.substr(i + from.size());
                    if (!vis.count(t)) {
                        vis.insert(t);
                        q.push({t, d + 1});
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    cin >> A >> B;
    string x, y;
    while (cin >> x >> y) rules.push_back({x, y});

    int res = bfs();
    if (res == -1) cout << "NO ANSWER!" << endl;
    else cout << res << endl;
    return 0;
}
*/