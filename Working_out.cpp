#include<bits/stdc++.h>
using namespace std;
#define int long long
int grid[1005][1005];
int dp1[1005][1005];
int dp2[1005][1005];
int dp3[1005][1005];
int dp4[1005][1005];
int n, m;
int ans = 0;
int32_t main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> grid[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			dp1[i][j] = grid[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);
	for(int i = n; i > 0; i--) 
		for(int j = 1; j <= m; j++)
			dp2[i][j] = grid[i][j] + max(dp2[i + 1][j], dp2[i][j - 1]);
	for(int i = n; i >= 1; i--)
		for(int j = m; j >= 1; j--)
			dp3[i][j] = grid[i][j] + max(dp3[i + 1][j], dp3[i][j + 1]); 
	for(int i = 1; i <= n; i++)
		for(int j = m; j >= 1; j--)
			dp4[i][j] = grid[i][j] + max(dp4[i - 1][j], dp4[i][j + 1]);
	for(int i = 2; i < n; i++)
		for(int j = 2; j < m; j++) {//intersection should happen from (2->m - 1) only at corners not possible to intersect at one point only
			int case1 = dp1[i - 1][j] + dp3[i + 1][j] + dp2[i][j - 1] + dp4[i][j + 1];
			int case2 = dp1[i][j - 1] + dp3[i][j + 1] + dp2[i + 1][j] + dp4[i - 1][j];
			ans = max(ans, max(case1, case2));
		}
		cout << ans;
	}