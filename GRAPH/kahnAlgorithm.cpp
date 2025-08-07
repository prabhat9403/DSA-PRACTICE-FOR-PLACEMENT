#include <bits/stdc++.h>
using namespace std;

void topoSort( vector<vector<int>> &adj, vector<int> &vis, vector<int>&inDegree,queue<int>&q)
{
  while(!q.empty()){
    int node=q.front();

    q.pop();
    for(auto it :adj[node]){
      inDegree[it]--;
      if(inDegree[it]==0){
        q.push(it);
      }
    }
    cout<<node<<" ";
  }
}
int main()
{
  int v;
  cin >> v;
  vector<vector<int>> adj(v);
  vector<int> vis(v, 0);
  vector<int> inDegree(v, 0);
  queue<int>q;
  
  
  for (int i = 0; i < v; i++)
  {
    while (10)
    {
      int val;
      cin >> val;
      if (val == -1)
        break;
      adj[i].push_back(val);
    }
  }
  for (int i = 0; i < v; i++)
  {
    for(auto it:adj[i]){
      inDegree[it]++;
    }
  }
  for(int i=0;i<v;i++){
    if(inDegree[i]==0){
      q.push(i);
    }
  }
  topoSort(adj,vis,inDegree,q);

  return 0;
}