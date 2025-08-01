#include <bits/stdc++.h>
using namespace std;
int delrow[] = {-1, 0, +1, 0};
int delcol[] = {0, 1, 0, -1};


void dfs(int n,int m,vector<vector<char>> &grid, vector<vector<int>> &vis, queue<pair<int, int>> &q)
{
   
  while(!q.empty()){
    int r=q.front().first;
    int c=q.front().second;
    q.pop();
    vis[r][c]=1;

    for(int i=0;i<4;i++){
      int nr=r+delrow[i];
      int nc=c+delcol[i];

      if(nr>=0&&nr<n&&nc>=0&&nc<m&&!vis[nr][nc]&&grid[nr][nc]=='o'){
        q.push({nr,nc});
      }
    }
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<char>> grid(n, vector<char>(m));
  vector<vector<int>> vis(n, vector<int>(m));

  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
      if (grid[i][j] == 'o' && (i == 0 || i == n - 1 || j == 0 || j == m - 1))
      {
        q.push({i, j});
      }
    }
  }

  dfs(n,m,grid,vis,q);
   for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if(grid[i][j]=='o'&&!vis[i][j]){
        grid[i][j]='x';
      }
    }
    
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}