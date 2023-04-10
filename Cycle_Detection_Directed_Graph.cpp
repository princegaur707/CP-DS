#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph {
	map<T, list<T>>l;
public:
	void AddEdge(T x, T y) {//directed graph so add in list one way
		l[x].push_back(y);
	}
	bool DFS_Helper(T src, map<T, bool>visited, map<T, bool>stack) {
		visited[src] = true;
		stack[src] = true;
		for(auto nbr: l[src]) {
			if((!visited[nbr] and DFS_Helper(nbr, visited, stack) or stack[nbr])) //1
				return true;
		}
		stack[src] = false;//backtracking as we are considering one path at a time  
		return false;
	}
	//Compactible with multiple components too
	bool DFS() {
		map<T, bool>visited, stack;
		for(auto x : l) {//extra loop due to multiple components
			if(!visited[x.first]) {//if node not visited
				bool cycle_found = DFS_Helper(x.first, visited, stack);
				if(cycle_found == 1)
					return true;
			}
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
	if(g.DFS())
		cout << "Cycle exist";
	else
		cout << "Cycle Don't exist";
}
/*
1 -> Probability of cycle existence ->
if((!visited and DFS_Helper(nbr, visited, stack)) or stack[nbr])
if node is not visited and there is existence of cycle in the same path after this node or directly 
this neighbour already occurred in the existing path
*/







