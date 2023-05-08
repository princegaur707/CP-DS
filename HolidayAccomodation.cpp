//Observations:
//N nodes N -1  edges implies no cycle as all nodes are connected that's why DFS can be applied
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
	int DFS(T node, unordered_map<T, bool>&visited, int *count, int &ans) {//& with ans is must as we want to save 
		visited[node] = true;
		count[node] = 1;//counting itself
		for(auto children: m[node]) {
			int dx = children.second;//representing distance or weight of edge
			if(!visited[children.first]){
				count[node] += DFS(children.first, visited, count, ans); 
				int right = count[children.first];
				int left = n - right;//as remaining nodes will be on left
				ans += 2 *  min(left, right) * dx;//fixed formula in this situation
			}
		}
		return count[node];
	}
	int Holiday() {
		unordered_map<T, bool>visited;
		int *count = new int[n];
		for(int i = 0; i < n; i++)
			count[i] = 0;
		int ans = 0;
		DFS(0, visited, count, ans);//considering 0 as starting point
		return ans;
	}
};
int main() {
	int t;
	cin >> t;
	int cnt = 0;
	while(t--) {
		cnt++;
		Graph<int>g;
		cin >> n;
		for(int i = 1; i < n; i++) { //1 to n => n - 1 edges
			int x, y, z;
			cin >> x >> y >> z;
			g.AddEdge(x - 1, y - 1, z);//Taking from '0' only
		}
		cout << "Case #" << cnt << ": " << g.Holiday() << endl;
 	}
}