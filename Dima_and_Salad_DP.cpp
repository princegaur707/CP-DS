//Here we have 2 parameters so 2D array required
//Shift is required as sum can be negative but we can have +ve indexes only so to accomodate that
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define size 100005
int n, k;
int *taste, *calorie;
int shift = 1e5 + 2;
int dp[101][2*size];
int Dima_and_Salad(int i, int sum) {
	if(i == n) {
		if(sum == 0)
			return 0;
		return -1e12;
	}
	if(dp[i][sum + shift] != -1)
		return dp[i][sum + shift];
	int option1 = taste[i] + Dima_and_Salad(i + 1, sum + taste[i] - k * calorie[i]);
	int option2 = 0 + Dima_and_Salad(i + 1, sum);
	return dp[i][sum + shift] = max(option1, option2);
}
int32_t main() {
	cin >> n >> k;
	taste = new int[n];
	calorie = new int[n];
	for(int i = 0; i < 101; i++) {
		for(int j = 0; j < 2 * size; j++)
			dp[i][j] = -1;
	}
	for(int i = 0; i < n; i++)
		cin >> taste[i];
	for(int i = 0; i < n; i++)
		cin >> calorie[i];
	int ans = Dima_and_Salad(0, 0);
	if(ans <= 0)
			cout << "-1";
	else
		cout << ans;
}