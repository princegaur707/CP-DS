#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, p;
template<typename T>
class Graph {
	unordered_map<T, list<T>>h;
public:
	void AddEdge(T x, T y, bool bidirection = true) {
		h[x].push_back(y);
		if(bidirection == true) 
			h[y].push_back(x);
	}
	void DFS(T node, unordered_map<T, bool>&visited, int &count) {
		visited[node] = true;
		count++;
		for(auto children: h[node])
			if(!visited[children])
				DFS(children, visited, count);
	}
	void JourneyToTheMoon() {
		unordered_map<T, bool>visited;
		int total = (n * (n - 1)) / 2; //nC2 = (n * (n- 1)) / 2
		int count = 0;
		DFS(0, visited, count);//This step is not compulsory but it significantly reduces the 
		//loop count if component count is '1' or only little higher
		total -= (count * (count - 1)) / 2; 
		for(auto node : h) {
			count = 0;//everytime new count for new component
			if(!visited[node.first]) {
				DFS(node.first, visited, count);
				total -= (count * (count - 1)) / 2;
			}
		}
		cout << total << endl;
	}
};
int32_t main() {
	Graph<int>g;
	cin >> n >> p;
	for(int i = 0; i < p; i++) {
		int x, y;
		cin >> x >> y;
		g.AddEdge(x, y);
	}
	g.JourneyToTheMoon();
}