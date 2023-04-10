#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph {
  map<T, list<T>>m;
public:
  void AddEdge(T x, T y) {
    m[x].push_back(y);
    m[y].push_back(x);
  }
  bool DFS_Helper(int node, int parent, int* visited, int color) {
    visited[node] = color;
    for(auto x : m[node]) {
      if(!visited[x]) {
        bool ans = DFS_Helper(x, node, visited, 3 - color);
        if(ans == 0) 
          return false;
      }
      else if(visited[x] == color)
        return false;
    }
    return true;
  }
  bool DFS(T n) {
    T visited[n] = {0};
    int color = 1;
    int ans = DFS_Helper(0, -1, visited, color);
    for(int i = 0; i < n; i++) 
      cout << i << " - Color -> " << visited[0] << endl;
    return ans;
  }
};
int main() {
  Graph<int>g;
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    g.AddEdge(x, y);
  }
  g.DFS(n);
}