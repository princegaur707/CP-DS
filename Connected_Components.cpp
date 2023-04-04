#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph {
public:
	map<T, list<T>>m;
	map<T, bool>visited;
	void AddEdge(T x, T y) {
		m[x].push_back(y);
		m[y].push_back(x);
	}
	void Components(T src) {
		cout << src << " ";
		visited[src] = true;
		for(auto x : m[src]) {
			if(!visited[x])
				Components(x);
		}
	}
	void DFS(T src) {
		int cnt = 0;
		for(auto x : m) {
			if(!visited[x.first]){
				cout << "Component No. " << cnt << " --> ";
				Components(x.first);
				cout << endl;
				cnt++;
			}
		}
		cout << "Total Components:" << cnt;
	}
};
int main() {
	Graph<int>g;
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int s, t;
		cin >> s >> t;
		g.AddEdge(s, t);
	}
	g.DFS(0);
}