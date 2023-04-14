#include<bits/stdc++.h>
using namespace std;
class Graph {
	list<pair<int, int>>l;
public:
	void AddEdge(int x, int y) {
		l.push_back({x, y});
	}
	int Find(int x, int* parent) {
		if(parent[x] == -1)
			return x;
		return parent[x] = Find(parent[x], parent);//with this dp approach(path compression) T.C: O(1)
	}
	void union_set(int m, int n, int *parent, int *rank) {
		int s1 = Find(m, parent);
		int s2 = Find(n, parent);
		if(s1 != s2) {//obvious that's why we want to join both so can be skipped
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
	bool Cycle(int n) {
		int *parent = new int[n];
		int *rank = new int[n];
		for(int i = 0; i < n; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}
		for (auto edge : l) {//finding from where edge start and where it ends
			int x = edge.first;//1
			int y = edge.second;//2
			int s1 = Find(x, parent);
			int s2 = Find(y, parent);
			if(s1 != s2)//this means no same parents this implies no cycle presence
				union_set(s1, s2, parent, rank);
			else
				return true;
		}
		return false;	
	}
};
int main() {
	Graph g;
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		g.AddEdge(x, y);
	}
	cout << g.Cycle(n) << endl;
}