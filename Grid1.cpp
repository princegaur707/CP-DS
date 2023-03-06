// Same appoach as Unique path iterative one just marked 
//cells after # at the corner can't be visited as '0'
#include<bits/stdc++.h>
using namespace std;
#define int long long
char grid[1002][1002];
int dp[1002][1002];
#define mod 1000000007;

int Solve(int h, int w) {
	dp[1][1] = 1;
	for(int i = 1; i <= h; i++) {
		for(int j = 1; j <= w; j++) {
			if(i == 1 or j == 1) {
				if(dp[i - 1][j] or dp[i][j - 1])
					dp[i][j] = 1;
				if(grid[i][j] == '#')
					dp[i][j] = 0;
			}
			else
				if(grid[i][j] != '#')
					dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
		}
	}
	return dp[h][w] % mod;
}
int32_t main() {
	int h, w;
	cin >> h >> w;
	for(int i = 1; i <= h; i++) {
		for(int j = 1; j <= w; j++) {
				cin >> grid[i][j];
		}
	}
	cout << Solve(h, w) << endl;
}