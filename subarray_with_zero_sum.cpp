#include<bits/stdc++.h>
using namespace std;
// check if there exists a subarray with sum 0;
//we used set instead of set as for map we needed 2 things needed to store map<pair<int,int>>m;
bool solve(int *a, int n) {
	unordered_set<int>s;
	//unordered_map<int, int>m;

	int pre = 0;//Running Sum store

	for (int i = 0; i < n; i++) {
		pre += a[i];
		if (pre == 0 or s.find(pre) != s.end()) {
			return true;
		}
		s.insert(pre);
	}
	return false;
}
//TC for set : O(NlogN) TC for Unordered set(this one): O(N)
int main() {
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++) 
		{
			cin >> a[i];
		}

		cout << solve(a, n) << endl;
	}
}
