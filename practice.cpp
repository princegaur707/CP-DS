#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
vector<int>gr[N];

bool DFS_Helper(int node, int parent, int* visited, int color) {
  visited[node] = color;
  for (auto nbr : gr[node]) {
    if (visited[nbr] == 0) {
      int small_ans = DFS_Helper(nbr, node, visited, 3 - color);
      if (small_ans == 0)
        return false;
    }
    else if (nbr != parent and visited[nbr] == color)
      return false;
  }
  return true;
}

//We are assuming only one component is there which is 90% of the time
bool DFS(int n) {
  int visited[n] = {0};
  int ans = DFS_Helper(0, -1, visited, color);//1
  for (int i = 0; i < n; i++)
    cout << i << " - Color -> " << visited[i] << endl;
  return ans;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    gr[x].push_back(y);
    gr[y].push_back(x);
  }
  if (DFS(n) == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
/*
Approach: By traversing via DFS if encounter any situation where child of the
element is already visited and is colored same as parent then it is not a
bipartitie graph
#1-> assuming we are starting from vertices '0'
*/