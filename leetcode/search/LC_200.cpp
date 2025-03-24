#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
void dfs(vector<vector<char>>& grid, int r, int c) 
{
        int nr = grid.size();
        int nc = grid[0].size();

        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c);
        if (r + 1 < nr && grid[r+1][c] == '1') dfs(grid, r + 1, c);
        if (c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c - 1);
        if (c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c + 1);
}


int numIslands(vector<vector<char>>& grid) 
{
    int nr = grid.size();
    if (!nr) return 0;
    int nc = grid[0].size();

    int num_islands = 0;
    for (int r = 0; r < nr; ++r)
	{
        for (int c = 0; c < nc; ++c) 
		{
            if (grid[r][c] == '1') 
			{
                ++num_islands;
                dfs(grid, r, c);
            }
        }
    }

    return num_islands;
}
int main()
{
	int n,m;
	char x;
	scanf("%d %d",&n,&m);
	vector<vector<char>>g(n, vector<char>(m));

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			getchar();
			scanf("%c",&g[i][j]);
			
		}
	}
	int ans=numIslands(g);
	printf("%d",ans);

    return 0;
}
/*
4 5
1 1 1 1 0
1 1 0 1 0
1 1 0 0 0
0 0 0 0 0
*/

/*
4 5
1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1
*/

