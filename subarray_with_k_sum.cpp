#include<bits/stdc++.h>
using namespace std;
bool solve(int *a, int n, int k) {
	unordered_set<int>s;
	int pre = 0;//Running Sum store

	for (int i = 0; i < n; i++) {
		pre += a[i];
		if (pre == k or s.find(pre - k) != s.end()) {
			return true;
		}
		s.insert(pre);
	}
	return false;
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		int k;
		cin >> n >> k;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << solve(a, n, k) << endl;
	}
}