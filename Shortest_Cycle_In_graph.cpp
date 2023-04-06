#include<bits/stdc++.h>
using namespace std; 
const int N = 100005;
vector<int>G[N];//vector of array instead of class
void AddEdge(int x, int y) {
	G[x].push_back(y);
	G[y].push_back(x);
}
void BFS(int src, int n, int &ans) {
	vector<int>distance(n + 1, INT_MAX);
	vector<int>parent(n + 1, -1);
	queue<int>q;
	q.push(src);
	distance[src] = 0;//distance for src from itself is '0'
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		for(auto nbr: G[x]) {//nbr->neighbour
			if(distance[nbr] == INT_MAX) {//unvisited node
				distance[nbr] = distance[x] + 1;
				parent[nbr] = x; 
				q.push(nbr);
			}
			else if(parent[x] != nbr and parent[nbr] != x and distance[nbr] <= distance[x]){//backedge exist
				//and distance[nbr] <= distance[x] -> will help in reducing some extra comparisons
				ans = min(ans, distance[nbr] + distance[x] + 1);
			}
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		AddEdge(x, y);
	}
	int ans = n + 1;//if n no. of nodes are there n+1 can never be answer
	for(int i = 1; i <= n; i++)//'1' based indexing 
		BFS(i, n, ans);	//1->V.I.Point to understand that we will have to find the length of cycle for every point as it will give different answers.
	if(ans == n + 1)
		cout << "No Cycle exist";
	else
		cout << "Shortest Cycle is of length: " << ans;
}
/*
#1-> While detecting the cycle if we are applying BFS/DFS on node which is not the part of the cycle then we will 
get the wrong answer.
backedge-> A node coming in path which is already visited and not the parent node of current node
*/