#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph {
public:
	map<T, list<T>>h;
	void AddEdge(T x, T y) {
		h[x].push_back(y);
		h[y].push_back(x);//assuming all edges bidirectional
	}
	void BFS(T idx) {
		queue<T>q;
		unordered_map<T, bool> visited;
		for(auto x : h)
			visited[x.first] = false;
		q.push(idx);
		visited[idx] = true;
		while(!q.empty()) {
			T t1 = q.front();
			cout << t1 << " ";
			q.pop();
			for(auto x : h[t1]) {
				if(!visited[x]){
					q.push(x);
					visited[x] = true;
				}
			}
		}
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
	g.BFS(0);
}