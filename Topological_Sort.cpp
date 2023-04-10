#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph {
	map<T, list<T>>l;
public:
	void AddEdge(T x, T y){
		l[x].push_back(y);
	}
	void DFS_Helper(T src, map<T, bool>&visited, list<T>&ordering) {
		visited[src] = true;
		for(auto nbr : l[src]) {
			if(!visited[nbr])
				DFS_Helper(nbr, visited, ordering);
		}
		ordering.push_front(src);
		return;
	}
	void DFS() {
		map<T, bool>visited;
		list<T>ordering;
		for(auto x : l) {//Assuming multiple components exist
			T node = x.first;
			if(!visited[node])
				DFS_Helper(node, visited, ordering);
		}
		for(auto x: ordering)
			cout << x << " ";
	}
	void BFS(int n) {
		map<T, int>indegree;
		for (auto x : l)
			indegree[x.first] = 0;
		//Resolving the indegree of the graph
		for(auto x : l)
			for(auto p : x.second)
				indegree[p]++;
		//Actual BFS starting
		queue<T>q;
		for(auto x : indegree) {
			if(x.second == 0)
				q.push(x.first);
		}
		while(!q.empty()) {
			T node = q.front();
			cout << node << " ";
			q.pop();
			for(auto nbr: l[node]) {
				indegree[nbr]--;
				if(indegree[nbr] == 0)
					q.push(nbr);
			}
		}
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
	g.DFS();
	cout << endl;
	g.BFS(0);
}