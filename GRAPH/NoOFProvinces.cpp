#include <bits/stdc++.h>
using namespace std;
int delrow[] = {-1, 0, +1, 0};
int delcol[] = {0, 1, 0, -1};

void dfs(int i, int j, int n, int m, vector<vector<int>> &am, vector<vector<int>> &vis)
{
  vis[i][j] = 1;
  for (int k = 0; k < 4; k++)
  {

    int nr = i + delrow[k];
    int nc = j + delcol[k];

    if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && am[nr][nc] == 1)
    {
      dfs(nr, nc, n, m, am, vis);
    }
  }
}
int main()
{
  int n, m;
  cin >> n >> m;
  // adjacency matrix
  vector<vector<int>> am(n, vector<int>(m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {

      cin >> am[i][j];
    }
  }

  vector<vector<int>> vis(n, vector<int>(m));
  int component = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {

      if (!vis[i][j] && am[i][j]==1)
      {
        component++;
        dfs(i, j, n, m, am, vis);
      }
    }
  }
  cout << component;

  return 0;
}