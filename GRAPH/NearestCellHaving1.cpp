#include <bits/stdc++.h>
using namespace std;

int delrow[] = {-1, 0, +1, 0};
int delcol[] = {0, 1, 0, -1};

void find( int n, int m, vector<vector<int>> &grid, vector<vector<int>> &vis, queue<pair<pair<int, int>, int>>& q, vector<vector<int>>& dist)
{

  while (!q.empty())
  {
    int row = q.front().first.first;
    int col = q.front().first.second;
    int dis = q.front().second;


    q.pop();
    dist[row][col] = dis;

    for (int i = 0; i < 4; i++)
    {
      int nr = row + delrow[i];
      int nc = col + delcol[i];

      if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0 && !vis[nr][nc])
      {
        vis[nr][nc]=1;
        q.push({{nr, nc}, dis + 1});
      }
    }
  }
}
int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));
  vector<vector<int>> vis(n, vector<int>(m));
  vector<vector<int>> dist(n, vector<int>(m, 0));

  queue<pair<pair<int, int>, int>> q;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[i][j] == 1)
      {
        vis[i][j] = 1;
        
        q.push({{i, j}, 0});
      }
      else{
        vis[i][j]=0;
        
      }
    }
  }
  find(n,m,grid,vis,q,dist);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout<<dist[i][j]<<" ";
    }
    cout<<endl;
  }
  

  return 0;
}