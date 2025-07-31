#include <bits/stdc++.h>
using namespace std;
int delrow[] = {-1, 0, +1, 0};
int delcol[] = {0, 1, 0, -1};

// Using DFS

void floodFillDFS(int sr, int sc, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &vis,int newcolor, int initialColor){
  
  vis[sr][sc]=1;
  grid[sr][sc]=newcolor;

  for(int i=0;i<4;i++){
      int ngbrRow=sr+delrow[i];
      int ngbrcol=sc+delcol[i];
      if(ngbrRow<n&&ngbrRow>=0&&ngbrcol>=0&&ngbrcol<m&&grid[ngbrRow][ngbrcol]==initialColor&&!vis[ngbrRow][ngbrcol]){
        floodFillDFS(ngbrRow,ngbrcol,n,m,grid,vis,newcolor,initialColor);
      }
    }
  
  
}

// Using BFS
void floodFill(int sr, int sc, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &vis,int newcolor, int initialColor)
{
  queue<pair<int,int>>q;
  q.push({sr,sc});
  while(!q.empty()){
    pair<int,int> top = q.front();
    int row=top.first;
    int col=top.second;
    vis[row][col]=1;
    q.pop(); 
    grid[row][col]=newcolor;
    for(int i=0;i<4;i++){
      int ngbrRow=row+delrow[i];
      int ngbrcol=col+delcol[i];
      if(ngbrRow<n&&ngbrRow>=0&&ngbrcol>=0&&ngbrcol<m&&grid[ngbrRow][ngbrcol]==initialColor&&!vis[ngbrRow][ngbrcol]){
        q.push({ngbrRow,ngbrcol});
      }
    }
  }

}
int main()
{
  int n, m, newcolor;
  cin >> n >> m >> newcolor;
  // adjacency matrix
  vector<vector<int>> grid(n, vector<int>(m));
  vector<vector<int>> vis(n, vector<int>(m,0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {

      cin >> grid[i][j];
    }
  }
  int sr, sc;
  cin >> sr >> sc;
  int initialcolor=grid[sr][sc];
  // floodFill(sr,sc,n,m,grid,vis,newcolor,initialcolor);
  floodFillDFS(sr,sc,n,m,grid,vis,newcolor,initialcolor);
   for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {

      cout<< grid[i][j]<<" ";
    }
    cout<<endl;
  }


  return 0;
}