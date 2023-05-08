#include<bits/stdc++.h>
using namespace std;
int n;
template<typename T>
class Graph {
  unordered_map<T, list<pair<T, int>>>m;
public:
  void AddEdge(T x, T y, int distance) {
    m[x].push_back({y, distance});
    m[y].push_back({x, distance});
  }
  int DFS(T node, unordered_map<T, bool>&visited, int *nodes_till_here, int &ans) {
    visited[node] = true;
    nodes_till_here[node] = 1;
    for(auto children: m[node]) {
      int dx = children.second;
      if(!visited[children.first]) {
        nodes_till_here[node] += DFS(children.first, visited, nodes_till_here, ans);
        int right = nodes_till_here[children.first];
        int left = n - right;
        ans += 2 * min(left, right) * dx;
      }
    }
    return nodes_till_here[node];
  }
  int Holiday() {
    unordered_map<T, bool>visited;
    int *nodes_till_here = new int[n];
    int ans = 0;
    memset(nodes_till_here, 0, sizeof(nodes_till_here));
    DFS(0, visited, nodes_till_here, ans);
    return ans;
  }
};
int main() {
  Graph<int>g;
  int t;
  cin >> t;
  int count = 1;
  while(t--) {
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      g.AddEdge(x - 1, y - 1, z);
    }
    cout << "Case #" << count << ": " <<g.Holiday() << endl;
    count++;
  }
}