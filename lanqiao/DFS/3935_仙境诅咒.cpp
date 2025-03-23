//
// Created by supanx on 25-3-23.
//
#include <iostream>
#include <queue>
#define fo(x, y) for (int i=x; i<=y; i++)
using namespace std;
const int maxn=1e3+5;
int n, d, x[maxn], y[maxn];
int vis[maxn], u;
queue<int> q;
int rge(int i) {
    int xx=x[u]-x[i];
    int yy=y[u]-y[i];
    return xx*xx+yy*yy<=d*d;
}
void bfs() {
    q.push(1);
    vis[u]=1;
    while (!q.empty()) {
        u=q.front();
        q.pop();
        fo(1, n) {
            if (!vis[i] && rge(i)) {
                vis[i]=1;
                q.push(i);
            }
        }
    }
}
void dfs(int p) {
    vis[p]=1;
    for (int i=1; i<=n; i++) {
        if (!vis[i]) {
            int xx=x[p]-x[i];
            int yy=y[p]-y[i];
            if (xx*xx+yy*yy <= d*d) dfs(i);
        }
    }
}
int main() {
    cin >> n;
    fo(1, n) cin >> x[i] >> y[i];
    cin >> d;
//    bfs();
    dfs(1);
    fo(1, n) cout << vis[i] << endl;
    return 0;
}



/*
 * 5
0 0
1 1
0 1
1 0
2 2
1*/