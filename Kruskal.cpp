#include<bits/stdc++.h>
using namespace std;
#define int long long
class DSU {
	int *parent;
	int *rank;
public:
	DSU(int n) {
		parent = new int[n];
		rank = new int[n];
		for(int i = 0; i < n; i++) {
			parent[i] = -1;
			rank[i] = -1;
		}
	}
	int find(int x) {
		if(parent[x] == -1) 
			return x;
		return parent[x] = find(parent[x]);
	}
	void union_set(int x, int y) {
		int s1 = find(x);
		int s2 = find(y);
		if(s1 != s2) {
			if(rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
			else {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}
};
class Graph {
	vector<vector<int>>edgelist;
	int V;
public:
	Graph(int V) {
		this->V = V;
	}
	void AddEdge(int x, int y, int w) {//w->weight
		edgelist.push_back({x, y, w});
	}
	int Kruskal_mst() {
		DSU s(V);
		sort(edgelist.begin(), edgelist.end());
		int ans = 0;
		for(auto edge : edgelist) {
			int x = edge[0];
			int y = edge[1];
			int w = edge[2];
			if(s.find(x) != s.find(y)) {
				s.union_set(x, y);
				ans += w;
			}
		}
		return ans;
	}
};
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	Graph g(n);
	for(int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		g.AddEdge(x - 1, y - 1, w);
	}
	cout << g.Kruskal_mst() << endl;
	return 0;
}