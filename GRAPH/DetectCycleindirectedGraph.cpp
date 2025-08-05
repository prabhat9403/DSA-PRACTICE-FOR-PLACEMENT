#include<bits/stdc++.h>
using namespace std;
bool hasCycle(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&Pathvis){
  vis[node]=1;
  Pathvis[node]=1;

  for(auto it:adj[node]){
    if(!vis[it]){
      if(hasCycle(it,adj,vis,Pathvis)==true)return true;
    }
    else if(Pathvis[it])return true;
  }
  Pathvis[node]=0;
  return false;

}
int main(){
  int v;
  cin>>v;
  vector<vector<int>>adj(v+1);
  vector<int>vis(v+1,0);
  vector<int>Pathvis(v+1,0);

  for (int i = 0; i < v; i++)
  {
    while(1){
      int val;
      cin>>val;
      if(val==-1){
        break; 
      }
      adj[i+1].push_back(val);
    }
  }
  for(int i=1;i<v+1;i++){
    if(!vis[i]){
      if(hasCycle(i,adj,vis,Pathvis)==true){
        cout<<"It has cycle";
        return 1;
      }
    }
  }
  cout<<"It has no cycle";
  return 0;
}