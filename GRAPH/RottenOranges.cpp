#include <bits/stdc++.h>
using namespace std;
int delrow[] = {-1, 0, +1, 0};
int delcol[] = {0, 1, 0, -1};

void RottenTheGrid(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &vis,vector<vector<int>> &t, int time)
{

  queue<pair<pair<int, int>, int>> q;

  // Pushed all the Rotten oranges
  q.push({{0, 0}, 0});
  q.push({{2, 1}, 0});

  while (!q.empty())
  { 
    pair<pair<int,int>,int>top=q.front();
    int row=top.first.first;
    int col=top.first.second;
    int time=top.second;

    q.pop();


    vis[row][col] = 1;
    t[row][col] = min(time,t[row][col] );
    for (int k = 0; k < 4; k++)
    {

      int nr = row + delrow[k];
      int nc = col + delcol[k];

      if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1)
      {
        q.push({{nr,nc},time+1});
      }
    }
  }
}
int main()
{
  int n, m;
  cin >> n >> m;
  // adjacency matrix
  vector<vector<int>> grid(n, vector<int>(m));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {

      cin >> grid[i][j];
    }
  }

  vector<vector<int>> vis(n, vector<int>(m, 0));
  vector<vector<int>> t(n, vector<int>(m, INT_MAX));

  RottenTheGrid(0, 0, n, m, grid, vis,t, 0);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if(t[i][j]==INT_MAX)cout<<"oo ";
      else{

        cout << t[i][j] << " ";
      }
    }
    cout << endl;
  }

  return 0;
}