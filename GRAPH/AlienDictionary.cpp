#include<bits/stdc++.h>
using namespace std;
void topoSort(int node, vector<vector<int>> &adj, vector<int> &vis,stack<int> &topo)
{
  vis[node] = 1;
  for (auto ngbr : adj[node])
  {
    if (!vis[ngbr])
    {

      topoSort(ngbr, adj, vis,topo);
    }
  }
  topo.push(node);
}
int main(){
  int N;
  int K;
  cin>>N>>K;
  vector<string>dict(K);

 for(int i=0;i<K;i++){
    cin>>dict[i];
  }
  vector<vector<int>>adj(N);
  vector<int>vis(N,0);
  stack<int>st;

  for(int i=0;i<K-1;i++){
      int j=0;
      int k=0;
      string str1=dict[i];
      string str2=dict[i+1];
      while(j<str1.length()
      &&k<str2.length()){
        if(str1[j]!=str2[k]){
          adj[str1[j]-'a'].push_back(str2[k]-'a');
          break;
        }
        j++;
        k++;
      }
  }
  for (int i = 0; i < N; i++)
  {
    if (!vis[i])
    {
      topoSort(i, adj, vis,st);
    }
  }
  while(!st.empty()){
    cout<<char(st.top()+'a')<<" ";
    st.pop();
  }



  return 0;

}