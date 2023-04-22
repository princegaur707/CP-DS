// https://www.spoj.com/problems/MST/
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
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
		bool* visited = new bool[V] {0};
		pq.push({0, 0});//{weight, node} weight first as we need to sort according to it
		int ans = 0;
		while(!pq.empty()) {
			auto temp = pq.top();
			pq.pop();
			int to_edge = temp.second;
			int weight = temp.first;
			if(visited[to_edge])
				continue;
			ans += weight;
			visited[to_edge] = 1;
			for(auto nbr : l[to_edge]) {
				if(visited[nbr.first] == 0)
					pq.push({nbr.second, nbr.first});
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
		g.AddEdge(x - 1, y - 1, w);//as we used '0' based indexing while in question '1' based is used
	}
	cout << g.Prim_MST();
}