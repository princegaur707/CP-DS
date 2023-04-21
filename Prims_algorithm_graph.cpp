#include<bits/stdc++.h>
using namespace std;
class Graph {
	vector<pair<int, int>>*l;
	int V;
public:
	Graph(int n) {
		V = n;
		l = new vector<pair<int, int>>[n];
	}
	void AddEdge(int x, int y, int w) {
		l[x].push_back({y, w});
		l[y].push_back({x, w});
	}
	int Prim_MST() {
		//Making min heap
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
		bool* visited = new bool[V] {0};
		q.push({0, 0});//weight, node
		int ans = 0;
		while(!q.empty()) {
			auto x = q.top();
			q.pop();
			int to_edge = x.second;
			int weight = x.first;
			if(visited[to_edge])
				continue;
			ans += weight;
			visited[to_edge] = 1;
			for(auto nbr : l[to_edge]) {
				if(visited[nbr.first] == 0)
					q.push({nbr.second, nbr.first});
			}
		}
		return ans;
	}
};
int main() {
	int n, m;
	cin >> n >> m;
	Graph g(n);
	for(int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		g.AddEdge(x - 1, y - 1, w);
	}
	cout << g.Prim_MST() << endl;
}