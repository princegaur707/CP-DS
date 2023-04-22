#include<bits/stdc++.h>
using namespace std;
class Graph {
  int V;
  vector<pair<int, int>>*l;
public:
  Graph(int n) {
    V = n;
    l = new vector<pair<int, int>>[n];
  }
  void AddEdge(int x, int y, int w) {
    l[x].push_back({y, w});
    l[y].push_back({x, w});
  }
  int Prims_MST() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    pq.push({0, 0});
    int ans = 0;
    bool *visited = new bool[V] {0};
    while (!pq.empty()) {
      auto temp = pq.top();
      pq.pop();
      int to_edge = temp.second;
      int weight = temp.first;
      if (visited[to_edge])
        continue;
      visited[to_edge] = 1;
      ans += weight;
      for (auto nbr : l[to_edge])
        if (!visited[nbr.first])
          pq.push({nbr.second, nbr.first});
    }
    return ans;
  }
};
int main() {
  int n, m;
  cin >> n >> m;
  Graph g(n);
  for (int i = 0; i < m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    g.AddEdge(x - 1, y - 1, w);
  }
  cout << g.Prims_MST();
}