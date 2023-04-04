#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph {
public:
	map<T, list<T>>l;
	void AddEdge(T x, T y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void SingleSourceDistance(T src) {
		map<T, int>distance;
		queue<T>q;
		for (auto x : l)
			distance[x.first] = INT_MAX;//
		q.push(src);
		distance[src] = 0;
		while (!q.empty()) {
			T node = q.front();
			q.pop();
			for (auto nbr : l[node]) {
				if (distance[nbr] == INT_MAX) {
					q.push(nbr);
					distance[nbr] = distance[node] + 1;
				}
			}
		}
		for(auto x : l) {
			cout << x.first << "-->" << distance[x.first] << endl;
		}
	}
};
int main() {
	Graph<int>g;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		g.AddEdge(x, y);
	}
	g.SingleSourceDistance(0);
}