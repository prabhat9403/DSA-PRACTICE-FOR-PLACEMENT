#include <bits/stdc++.h>
using namespace std;
int dfs(int node,vector<int> al[],vector<int> &vis){
    vis[node]=1;
    for(auto it:al[node]){
      if(!vis[it]){
        dfs(it,al,vis);
      }
    }
}
int main()
{
  int v;
  cin >>v;
  vector<int> al[v];
  for (int i = 0; i <v; i++)
  {
    int n;
    cin>>n;
    vector<int>ngbr(n);
    for(int i=0;i<n;i++){
      cin>>ngbr[i];
    }
    al[i]=ngbr;
    
  }
  vector<int>vis(v,0);
  int component=0;
  for(int i=0;i<v;i++){
    if(!vis[i]){
      component++;
      dfs(i,al,vis);
    }
  }
  cout<<component;

  return 0;
}