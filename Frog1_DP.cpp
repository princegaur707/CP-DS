#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int arr[100005];
vector<int>dp(100005, -1);
int Solve(int i) {
	if(i == n)
		return 0;
	if(dp[i] != -1) 
		return dp[i];
	int option1 = INT_MAX;
	int option2 = INT_MAX;
	option1 = abs(arr[i + 1] - arr[i]) + Solve(i + 1);
	if(i + 2 <= n)
		option2 = abs(arr[i + 2] - arr[i]) + Solve(i + 2);
	return dp[i] = min(option1, option2);
}
int32_t main() {
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> arr[i];
	cout << Solve(1) << endl;
} 