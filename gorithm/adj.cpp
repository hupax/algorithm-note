//
// Created by 沙枭 on 24-5-7.
//
#include <iostream>
#include <vector>
using namespace std;

const int M = 105;  // 最大顶点数
int vis[M];  // 标记数组

struct edge
{
  int v;  // 顶点
  int w;  // 边的权重
};

vector<edge> adj[M];  // 邻接表(二维)

//
void dfs(int u)
{
    vis[u] = 1; // 标记已访问
    cout << u << " ";  // 输出顶点编号
    
    // 遍历u所有的邻接点
    // for (const auto &edge : adj[u]) {
    for (int i = 0; i < adj[u].size(); ++i)
    {
        int v = adj[u][i].v;
        if (!vis[v])
        {
            dfs(v);  // 递归访问v
        }
    }
}
int main()
{
    int n, m;  // 顶点数n， 边数m
    cin >> n >> m;
    
    // 初始化
    memset(vis, 0, sizeof(vis));
    
    for (int i = 0; i < n; ++i)
    {
        int u, v, w;  // u为顶点， v为边，w为权重
        cin >> u >> v >> w;
        edge newNode = {v, w};  // 新节点
        adj[u].push_back(newNode);
    }
    
    // 从每个未访问的顶点开始进行DFS遍历
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {
            dfs(i);  //
            cout << endl;  // 遍历完一个连通分量后换行
        }
    }
    
    return 0;
}
/*
1 2 1
2 3 3
3 4 5
1 3 4
1 4 2
 */