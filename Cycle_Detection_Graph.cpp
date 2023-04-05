#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph {
public:
	unordered_map<T, list<T>>m;
	unordered_map<T, bool>visited;
	void AddEdge(T x, T y) {
		m[x].push_back(y);
		m[y].push_back(x);
	}
	bool CycleDetection(T src, T parent) {
		visited[src] = true;
		for(auto x : m[src]) {
			if(!visited[x]) {
				bool cycle = CycleDetection(x, src);
				if(cycle)
					return true;
			}
			else if(x != parent)
				return true;
		}
		return false;
	}
};
int main() {
	Graph<int>g;
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		g.AddEdge(x, y);
	}
	if(g.CycleDetection(1, -1))
		cout << "Cycle Detected";
	else
		cout << "No Cycle Detected";
}