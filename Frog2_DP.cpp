#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>dp(100005, -1);
int arr[100005];
int n, k;
int Solve(int i) {
	if(i > n)//This path is out of arr bounds so this is invalid path 
		return 1e9;//this invalid path never gets selected so we are returning value wich can never be answer
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
	for(int i = 1; i <= n; i++)
		cin >> arr[i];
	cout << Solve(1) << endl;
}