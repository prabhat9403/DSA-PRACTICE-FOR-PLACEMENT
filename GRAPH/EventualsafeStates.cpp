#include<bits/stdc++.h>
using namespace std;


bool hasCycle(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&Pathvis,vector<int>&check){
  vis[node]=1;
  Pathvis[node]=1;

  for(auto it:adj[node]){
    if(!vis[it]){
      if(hasCycle(it,adj,vis,Pathvis,check)==true)return true;
    }
    else if(Pathvis[it])return true;
  }
  Pathvis[node]=0;
  check[node]=1;
  return false;

}




int main(){
  int v;
  cin>>v;
  vector<vector<int>>adj(v);
  vector<int>vis(v,0);
  vector<int>Pathvis(v,0);
  vector<int>check(v,0);

  for (int i = 0; i < v; i++)
  {
    while(1){
      int val;
      cin>>val;
      if(val==-1){
        break; 
      }
      adj[i].push_back(val);
    }

  }

  for(int i=0;i<v;i++){
    if(!vis[i]){
      hasCycle(i,adj,vis,Pathvis,check);
    }
  }
  for(int i=0;i<v;i++){
    if(check[i]){
      cout<<i<<" ";
    }
  }
  
  
  return 0;
}