#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m;   
template<typename T>
class Graph {
	unordered_map<T, list<pair<T, int>>>l;
public:
	void AddEdge(T x, T y, int w) {
		l[x].push_back({y, w});
		l[y].push_back({x, w});
	}
	void BellmanFord(T src) {
		unordered_map<T, int>distance;
		for(auto x: l)
			distance[x.first] = INT_MAX;
		distance[src] = 0;
		int vertices = n;
		for(int i = 0; i < vertices - 1; i++) {
			for(auto node: l) {
				T u = node.first;
				for(auto children: l[u]) {
					T v = children.first;
					int edge_weight = children.second;
					if(distance[u] != INT_MAX and
						(distance[v] > distance[u] + edge_weight))
						distance[v] = distance[u] + edge_weight;
				}
			}
		}//To detect a negative edge cycle:


		//Even after you have relaxed v-1 types all the edges if there is an edge
		//whose current weight is < than weight of the parent+edge weight then
		//yes there exists a negative cycle:
		for (auto node : l) {
			T u = node.first;
			for (auto children : l[u]) {
				T v = children.first;
				int edge_weight = children.second;
				if (distance[u] != INT_MAX and (distance[v] > distance[u] + edge_weight)) {
					cout << "There exists a negative Edge cycle" << endl;
					return;
				}
			}
		}
		for(int i = 0; i <= n; i++) {
			cout << "Distance of " << i << " from src " << src << " is " <<
						distance[i] << endl;
		}
	}
};
int32_t main() {
	cin >> n >> m;
	Graph<int>g;
	for(int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		g.AddEdge(x, y, w);
	}
	int src;
	cin >> src;
	g.BellmanFord(src);
}