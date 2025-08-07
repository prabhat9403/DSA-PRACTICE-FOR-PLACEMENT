#include <bits/stdc++.h>
using namespace std;
int main()
{
  int V;
  cin >> V;
  int src;
  cin >> src;
  vector<vector<int>> adj(V);

  for (int i = 0; i < V; i++)
  {
    int val;
    while (1)
    {
      cin >> val;
      if (val == -1)
        break;
      adj[i].push_back(val);
    }
  }
  vector<int> vis(V);
  vector<int> dist(V, 1e9);
  queue<int> q;
  dist[src] = 0;

  q.push(src);

  while (!q.empty())
  {
    int node = q.front();
    q.pop();

    for (auto it : adj[node])
    {

      if (dist[it] > 1 + dist[node])
      {
        dist[it] = 1 + dist[node];
        q.push(it);
      }
    }
  }
  for (auto it : dist)
  {
    cout << it << " ";
  }

  return 0;
}