#include<bits/stdc++.h>
using namespace std;
// using dfs

bool detectCycle(vector<vector<int>>&adj,vector<int>&vis,int start,int parent){
  vis[start]=1;
  for(auto it:adj[start]){
    if(!vis[it]){
      detectCycle(adj,vis,it,start);
    }
    else if(it!=parent){
      return true;
    }
  }
  return false;
}

// using bfs
bool DetectCycle(vector<vector<int>>&adj,vector<int>&vis){
  queue<pair<int,int>>q;
  q.push({1,-1});
  vis[1]=0;
  while(!q.empty()){
    int node=q.front().first;
    int parent=q.front().second;
    q.pop();
   

    for(auto it:adj[node]){
      if(!vis[it]){
        q.push({it,node});
         vis[node]=1;
      }
      else if(it!=parent){
       return true;
      }
    }
  }
  return false;
}
int main(){
  int v;
  cin>>v;
  vector<vector<int>>adj(v);
  vector<int>vis(v,0);
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
  detectCycle(adj,vis,1,-1)?cout<<"Cycle Detected":cout<<"No Cycle Detected";
  
  return 0;
}