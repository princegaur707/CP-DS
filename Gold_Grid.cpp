#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[1001][1001];
int n, m;
void Solve() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) 
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j] + dp[i][j] - dp[i - 1][j - 1];
	}
	int ans = INT_MIN;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			int opt1 = dp[i][j];
			int opt2 = dp[i][n] - opt1;
			int opt3 = dp[n][j] - opt1;
			int opt4 = m - opt1 - opt2 - opt3;
			ans = max(ans, min({opt1, opt2, opt3, opt4}));
		}
	}
	cout << ans << endl;
}
int32_t main() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		dp[x][y]++;
	}
	Solve();
}