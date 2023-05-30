//Here we can easily deduce that DSU can find but issue is how 
//to apply DSU as if we have ['a', 'b', 'ab'] for every i we will
//to match from 0 to n
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
int n;
string s[200005];//string ka array like ['abc', 'bcd', 'cde']
int main() {
	DSU g(26);//we need 26 letters
	cin >> n;
	for(int i = 0; i < n; i++) {
		string s1;
		cin >> s1;
		s[i] = s1;
		for(int j = 0; j < s1.length() - 1; j++)//s1 length can be maximum of 50 so we can do this step 
			g.Union_Set(s1[j] - 'a', s1[j + 1] - 'a');
	}
	int c[26] = {0};//max. 26 superparents possible

	for(int i = 0; i < n; i++)//we need only those superparent which are occuring in question
		for(int j = 0; j < s[i].length(); j++)
			c[g.Find_Set(s[i][j] - 'a')]++;//updating those superparent occuring at least once
	
	int ans = 0;
	for(int i = 0; i < 26; i++)
		if(c[i])
			ans++;

	cout << ans;
}