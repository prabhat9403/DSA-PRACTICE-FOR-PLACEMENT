#include <bits/stdc++.h>
using namespace std;
void find()
{
  
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
    }
  }
  return 0;
}