#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph {
public:
  map<T, list<T>>h;
  void AddEdge(T x, T y, bool bdr) {
    h[x].push_back(y);
    if(bdr == 1)
      h[y].push_back(x);
  }
  void Print() {
    for(auto x : h) {
      T t1 = x.first;
      cout << t1 << " --> " ;
      list<T> t2 = x.second;
      for(auto y : t2)
        cout << y << " ";
      cout << endl;
    }
  }
};
int main() {
  Graph<string>g;
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    string t, u;
    cin >> t >> u;
    g.AddEdge(t, u, 1);
  }
  g.Print();
}
