#include<bits/stdc++.h>
using namespace std;
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
	int Find_Set(int a) {
		if(a == parent[a])
			return a;
		return parent[a] = Find_Set(parent[a]);
	}
	void Union_Set(int a, int b) {
		a = Find_Set(a);
		b = Find_Set(b);
		if(a != b) {
			if (rank[a] < rank[b])
				swap(a, b);
			parent[b] = a;
			if(rank[a] == rank[b])
				rank[a]++;
		}
	}
};
int n;
string s[200005];
int main() {
	DSU g(26);
	cin >> n;
	for(int i = 0; i < n; i++) {
		string s1;
		cin >> s1;
		s[i] = s1;
		for(int j = 0; j < s1.length() - 1; j++) 
			g.Union_Set(s1[j] - 'a', s1[j + 1] - 'a');
	}
	int c[26] = {0};
	for(int i = 0; i < n; i++)
		for(int j = 0; j < s[i].length(); j++)
			c[g.Find_Set(s[i][j] - 'a')]++;
	
	int ans = 0;
	for(int i = 0; i < 26; i++)
		if(c[i])
			ans++;

	cout << ans;
}