//
// Created by supanx on 25-3-13.
//
#include <iostream>
#include <vector>
using namespace std;

void bfs(vector<vector<char>> &g, int i, int j) {
    g[i][j] = '0';
    if (i+1 < g.size() && g[i+1][j] == '1')
        bfs(g, i+1, j);
    if (i-1 >= 0 && g[i-1][j] == '1')
        bfs(g, i-1, j);
    if (j+1 < g.size() && g[i][j+1] == '1')
        bfs(g, i, j+1);
    if (j-1 >= 0 && g[i][j-1] == '1')
        bfs(g, i, j-1);
    
}
int numIslands(vector<vector<char>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                ans++;
                bfs(grid, i, j);
            }
        }
    }
    return ans;
}
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<vector<char>> g = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    cout<<numIslands(g);
    
    return 0;
}