#include<bits/stdc++.h>
using namespace std;


int main(){
  int N;
  int P;
  cin>>N>>P;
  vector<vector<int>>courses(P,vector<int>(2));
  vector<int> vis(N, 0);
  vector<int> inDegree(N, 0);
  queue<int>q;

  for(int i=0;i<P;i++){
    cin>>courses[i][0]>>courses[i][1];
  }

  vector<vector<int>>adj(N);

  for(int i=0;i<P;i++){
    int u=courses[i][0];
    int v=courses[i][1];
    adj[v].push_back(u);
  }



  for (int i = 0; i < N; i++)
  {
    for(auto it:adj[i]){
      inDegree[it]++;
    }
  }
  for(int i=0;i<N;i++){
    if(inDegree[i]==0){
      q.push(i);
    }
  }
  int cnt=0;
  while(!q.empty()){
    int node=q.front();

    q.pop();
    for(auto it :adj[node]){
      inDegree[it]--;
      if(inDegree[it]==0){
        q.push(it);
      }
    }
    cnt++;
  }
  if(cnt==N)cout<<"Yes";
  else{
    cout<<"No";
  }

  return 0;
}