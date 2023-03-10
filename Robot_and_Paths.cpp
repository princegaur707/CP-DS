#include<bits/stdc++.h>
using namespace std;
// const int N = 0;

int n, m, p;
int grid[1002][1002] = {0};

#define mod 1000000007

int solve() {
	int dp[n + 1][m + 1] = {0};

	if (grid[1][1] == -1 or grid[n][m] == -1) {
		return 0;
	}

	dp[1][1] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 and j == 1) {
				continue;
			}
			if (grid[i][j] == -1) {
				dp[i][j] = 0;
			} else {
				dp[i][j] = (((i == 1) ? 0 : dp[i - 1][j]) + ((j == 1) ? 0 : dp[i][j - 1])) % mod;
			}
		}
	}
	return dp[n][m];
}

int main() {
	cin >> n >> m >> p;

	while (p--) {
		int x, y;
		cin >> x >> y;

		grid[x][y] = -1;
	}
	cout << solve() << endl;
}

//Another mine submitted appraoch:
#include <iostream>
using namespace std;
#define mod 1000000007
#define int long long
int grid[1005][1005];
int Solve(int m, int n) {
    int dp[m + 1][n + 1] = {0};
        if(grid[1][1] == -1 or grid[m][n] == -1)
            return 0;
        dp[1][1] = 1;
        for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == 1 or j == 1) {
                if(dp[i - 1][j] or dp[i][j - 1])
                    dp[i][j] = 1;
                if(grid[i][j] == -1)
                    dp[i][j] = 0;
            }
            else {
                if(grid[i][j] != -1)
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
            }
        }
    }
    return (dp[m][n]) % mod;
}
int32_t main() {
	int m, n, p;
	cin >> m >> n >> p;
	for(int i = 0; i < p; i++) {
	    int x, y;
	    cin >> x >> y;
	    grid[x][y] = -1;
	}
	cout << Solve(m, n);

}