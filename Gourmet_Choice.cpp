#include<bits/stdc++.h>
using namespace std;
#define int long long
class DSU {
	vector<int>parent, rank;
public:
	DSU(int n) {
		parent.resize(n);
		rank.resize(n);
		for(int i = 0; i < n; i++) {
			parent[i] = i;
			rank[i] = 0;
		}
	}
	int Find_Set(int a) {//tells the current superparent
		if(a == parent[a])
			return a;
		return parent[a] = Find_Set(parent[a]);//current node's parent will be parent's parent
	}
	void Union_Set(int a, int b) {
		a = Find_Set(a);
		b = Find_Set(b);
		if(a != b) {
			if (rank[a] < rank[b])
				swap(a, b);
			parent[b] = a;//already compared ranks so we can directly do this 
			if(rank[a] == rank[b])
				rank[a]++;
		}
	}
};
vector<pair<int, int>> edgelist;
vector<int>adjlist[2001];//array of vectors: from question at max 2000
bool visited[2004];
int depth[2001] = {0};
bool IsCyclePresent = false;
bool DFSCallStack[2004] = {0};

void FindDepth(int node) {
	if(visited[node])
		return;
	//Cycle exist in "Directed Graph" if we visit 
	//a node which is already visited and it is one
	//of the ancestor of the current DFS call.
	if(IsCyclePresent == true)
		return;
	if(DFSCallStack[node] == true) {
		IsCyclePresent = true;
		return;
	}
	DFSCallStack[node] = true;
	int d = 0;
	for(auto children: adjlist[node]) {
		FindDepth(children);
		d = max(d, depth[children]);
	}
	depth[node] = d + 1;
	DFSCallStack[node] = false;//false as we can reach this point from other ways too
	visited[node] = true;
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	DSU g(n + m);//because I'm considering 'j' as separate node
	for(int i = 0; i < n; i++) { 
		for(int j = 0; j < m; j++) {
			char ch;
			cin >> ch;
			if(ch == '=')
				g.Union_Set(i, n + j);//jth node will come after first n nodes will be over of 'i'
			else if(ch == '>')
				edgelist.push_back({i, n + j});//like 3 is child of 1 : 1 --> 3
			else
				edgelist.push_back({n + j, i});
		}
	}
	for(auto x : edgelist) 
		adjlist[g.Find_Set(x.first)].push_back(g.Find_Set(x.second));//like 3, 4 are child of 1 then 1 -> 3, 4
	
	for(int i = 0; i < n + m ; i++) {
		if(!visited[g.Find_Set(i)]) 
			FindDepth(g.Find_Set(i));
	}
	if(IsCyclePresent == 1)
		cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		for(int i = 0; i < n; i++)
			cout << depth[g.Find_Set(i)] << " ";
		cout << endl;
		for(int j = 0; j < m; j++)
			cout << depth[g.Find_Set(n + j)] << " "; 
	}	
}
