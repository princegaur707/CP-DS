#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>
class Graph {
  unordered_map<T,list<pair<T, int>>>l;
public:
  void AddEdge(T x, T y, int w) {
    l[x].push_back({y, w});
    l[y].push_back({x, w});
  }
  void Dijkstras(int src) {
    unordered_map<T, int>distance; //will use distance only for visited
    set<pair<int, int>>s;
    for(auto x : l) 
      distance[x.first] = INT_MAX;
    distance[src] = 0;
    s.insert({0, src});//weight, node
    int cnt = 0;
    while(!s.empty()) {
      auto p = *(s.begin());
      s.erase(s.begin());
      T node = p.second;
      T parent_weight = p.first;
      for(auto children : l[node]) {
        int edge_weight = children.second;
        if(distance[children.first] > parent_weight + edge_weight) {
          auto f = s.find({distance[children.first], children.first});
          if(f != s.end())
            s.erase(f);
          distance[children.first] = parent_weight + edge_weight; 
          s.insert({distance[children.first], children.first});
        }
      }
    }
    for(auto node : l) {
      cout << "Distance of " << node.first + 1 << " from src " << src + 1 << " is " <<
            distance[node.first] << endl; 
    }
  }
};
int32_t main() {
  int n, m;
  cin >> n >> m;
  Graph<int>g;
  for(int i = 0; i < m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    g.AddEdge(x - 1, y - 1, w);
  }
  int src;
  cin >> src;//source will be given by user
  g.Dijkstras(src - 1);
}