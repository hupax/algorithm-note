//
// Created by 沙枭 on 24-5-12.
//
// L2-001 紧急救援
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <chrono>
// lambda
using namespace std;
const int M = 505;
int n, m, st, ed;
int vis[M], d[M], pre[M];
unordered_map<int, int> mn;
int min_num = 1, num[M];
struct edge
{
  int v;
  int w;
  edge(int x, int y) : v(x), w(y)
  {
  }
};
auto comp = [](pair<int, int> &a, pair<int, int> &b)
{
  return a.second < b.second;
};
void bfs(vector<edge> adj[], int s)
{
//    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> q(comp);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.emplace(0, s);
//    vis[s] = 1;
    num[s] += mn[s];
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto &it : adj[u])
        {
            int
                v = it.v,
                w = it.w,
                len = d[u] + w,
                ct = num[u] + mn[v];
            if (len < d[v])
            {
                d[v] = len;
                pre[v] = u;
                q.emplace(w, v);
            }
            else if (len == d[v] && v == ed)
            {
                min_num++;
                if (num[v] < ct)
                {
                    num[v] = ct;
                    pre[v] = u;
                    continue;
                }
            }
            num[v] = ct;
        }
    }
}
void bfs_path(int u)
{
    if (u == st)
    {
        cout << st;
        return;
    }
    bfs_path(pre[u]);
    cout << " " << u;
}
int main()
{
    cin >> n >> m >> st >> ed;
    vector<edge> adj[n];
    fill(d, d + n + 1, INT_MAX);
    d[st] = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; ++i)
    {
        cin >> mn[i];
    }
    for (int i = 0; i < n; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }
    
    auto start = std::chrono::high_resolution_clock::now();
    
    bfs(adj, st);
    cout << min_num << " " << num[ed] << endl;
    bfs_path(ed);
    
    auto stop = std::chrono::high_resolution_clock::now();
    
    // 计算持续时间
    
//    auto duration = duration_cast<chrono::milliseconds>(stop - start);
    auto duration = duration_cast<chrono::nanoseconds>(stop - start);
    
    // 输出运行时间
    cout << endl;
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
}
/*
4 5 0 3
20 30 40 10
0 1 1
1 3 2
0 3 3
0 2 2
2 3 2

 */