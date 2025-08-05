#include<bits/stdc++.h>
using namespace std;
bool isBpartite(int start,int col,vector<vector<int>>&adj,vector<int>&vis,vector<int>&color){

  queue<pair<int,int>>q;
  q.push({start,col});
  while(!q.empty()){
    int node=q.front().first;
    int c=q.front().second;
    q.pop();
    vis[node]=1;
    color[node]=c;
     for(auto it :adj[node]){
      if(!vis[it]&&color[it]!=c){

        q.push({it,!c});
      }
      else{
        if(color[it]==c){
          return false;
        }
      }
     }

  }
  return true;
}



int main(){
  int v;
  cin>>v;
  vector<vector<int>>adj(v+1);
  vector<int>vis(v+1,0);
  vector<int>color(v+1,-1);
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
  isBpartite(1,0,adj,vis,color)?cout<<"This Graph is a Bipartite Graph":cout<<"This Graph is not a Bipartite Graph";
  return 0;
}