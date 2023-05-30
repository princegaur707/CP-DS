#include<bits/stdc++.h>
using namespace std;
class DSU {
	vector<int>parent, rank;
	int totalcomponents;
public:
	DSU(int n) {
		parent.resize(n);
		rank.resize(n);
		for(int i = 0; i < n; i++) {
			parent[i] = i, rank[i] = 0;
		}
		totalcomponents = n;
	}
	int Find_Set(int a) {
		if(a == parent[a])
			return a;
		return parent[a] = Find_Set(parent[a]);
	}
	void Union_Set(int a, int b) {
		a = Find_Set(a);
		b = Find_Set(b);
		if(a != b) {
			if(rank[a] < rank[b])
				swap(a, b);
			parent[b] = a;
			if (rank[a] == rank[b])
				rank[a]++;
			totalcomponents--;//as we are combining two components so decrease total components by one
		}
	}
};
int c[200005][26];//if every element belong to different DSU max 2*10^5 possible cases
int main() {
	int t;
	cin >> t;
	int n, k;
	string s;
	while(t--) {
		cin >> n >> k >> s;
		DSU g(n);
		//Joining acc. to condn 1 Palindrome
		for(int i = 0; i < n; i++)
			g.Union_Set(i, n - i - 1);
		//Joining acc. to condn 2 (i -> i + k)
		for(int i = 0; i < n - k; i++)
			g.Union_Set(i, i + k);
		memset(c, 0, sizeof(c));
		for(int i = 0; i < n; i++) 
			c[g.Find_Set(i)][s[i] - 'a']++;
		int ans = 0;
		for(int i = 0; i < n; i++) {
			if(g.Find_Set(i) == i) {//implies we hit the super_parent
				int total_frequency = 0;
				int max_occuring_char = 0;
				//row represent one component
				for(int j = 0; j < 26; j++) {
					total_frequency += c[i][j];
					max_occuring_char = max(max_occuring_char, c[i][j]);
				}
				ans += total_frequency - max_occuring_char;
			}
		}
		cout << ans << endl;
	}
}