#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<int>gr[N];
vector<int>rev_gr[N];
void DFS(bool *visited, vector<int>&stack, int node) {
	visited[node] = true;
	for(auto nbr: gr[node]) 
		if(!visited[nbr])
			DFS(visited, stack, nbr);
	stack.push_back(node);//ordering based on finish time 
}
void DFS2(bool *visited, int node) {
	visited[node] = true;
	cout << node << " ";
	for(auto nbr: rev_gr[node])
		if(!visited[nbr])
			DFS2(visited,nbr);
}
void Solve(int n) {//step 1: Apply DFS and get the array based on 
	bool visited[n] = {0};
	vector<int>stack;//in coreman stack is used
	for(int i = 0; i < n; i++)
		if(!visited[i])
			DFS(visited, stack, i);
	memset(visited, 0, sizeof(visited));//making visited array again '0'
	//for preparing for step 3 
	int component = 1;
	for(int i = stack.size() - 1; i >= 0; i--) {//moving right to left on stack
		int node = stack[i];
		if(!visited[node]) {
			cout << "Component " << component++ << "-> ";
			DFS2(visited, node);
			cout << endl;
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		rev_gr[y].push_back(x);//step 2 reversing the graph
	}
	Solve(n);
} 