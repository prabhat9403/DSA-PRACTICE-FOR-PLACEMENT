#include<bits/stdc++.h>
using namespace std;

void topo(int node,vector<vector<pair<int,int>>>&adj,vector<int>&vis,stack<int>&st){

  vis[node]=1;
  for(auto it:adj[node]){
    if(!vis[it.first]){
      topo(it.first,adj,vis,st);
    }
  }
  st.push(node);
}
int main(){
  int V;
  cin>>V;
  int src;
  cin>>src;
  vector<vector<pair<int,int>>>adj(V);

  for(int i=0;i<V;i++){
    int val,dist;
    while(1){
      cin>>val;
      if(val==-1)break;
      cin>>dist;
      adj[i].push_back({val,dist});
    }
  }
  vector<int>vis(V);
  stack<int>st;
  for(int i=0;i<V;i++){
    if(!vis[i]){
      topo(i,adj,vis,st);
    }
  }
  vector<int>dist(V,INT_MAX);
  dist[src]=0;


  while(!st.empty()){
    int node=st.top();
    int dis=dist[node];
    st.pop();

    for(auto it:adj[node]){
      if(dist[it.first]>dis+it.second){
        dist[it.first]=dis+it.second;
      }
    }
  }


  for(auto it:dist){
    cout<<it<<" ";
  }


  return 0;
}