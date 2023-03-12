#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>dp(100001, -1);
int arr[100005];
int n, k;
int Solve(int i) {
	if(i > n)
		return INT_MAX;
	if(i == n)
		return 0;
	if(dp[i] != -1)
		return dp[i];
	int ans = INT_MAX;
	for(int j = 1; j <= k; j++)
		ans = min(ans, abs(arr[i + j] - arr[i]) + Solve(i + j));
	return dp[i] = ans;
}
int32_t main() {
	cin >> n >> k;
	for(int i = 1; i <= k; i++)
		cin >> arr[i];
	cout << Solve(1);
}