#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define size 100005
int dp[101][2*size];
int taste[101], calorie[101];
int n, k;
int Solve(int ind, int sum) {
	if(ind == n - 1) {
		if(sum == 0)
			return 0;
		return -1e12;
	}
	if(dp[ind][sum] != -1)
		return dp[ind][sum];
	int option1 = taste[ind] + Solve(ind + 1, sum + (taste[ind] - k * calorie[ind]));
	int option2 = Solve(ind + 1, sum);
	return dp[ind][sum] = max(option1, option2);
}
int32_t main() {
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> taste[i];
	for(int i = 0; i < n; i++)
		cin >> calorie[i];
	for(int i = 0; i < 101; i++)
		for(int j = 0; j < 2 *size; j++)
			dp[i][j] = -1;
	int ans = Solve(0, 0);
	if(ans > 0)
		cout << ans;
	else
		cout << "-1";
}