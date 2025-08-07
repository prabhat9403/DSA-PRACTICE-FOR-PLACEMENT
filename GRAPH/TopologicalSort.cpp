#include <bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &topo)
{
  vis[node] = 1;
  for (auto ngbr : adj[node])
  {
    if (!vis[ngbr])
    {

      topoSort(ngbr, adj, vis, topo);
    }
  }
  topo.push(node);
}
int main()
{
  int v;
  cin >> v;
  vector<vector<int>> adj(v);
  vector<int> vis(v, 0);
  stack<int> topo;
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
    if (!vis[i])
    {
      topoSort(i, adj, vis, topo);
    }
  }
  while (!topo.empty())
  {
    cout << topo.top() << " ";
    topo.pop();
  }

  return 0;
}