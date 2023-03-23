#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n, m;
int a[5001], b[5001];
int dp[5001][5001];//2D dp is required
int Valentine_Magic(int i, int j) {
	//i --> is for boys
	if(i == n)//we have iterated over all the boys
		return 0;
	if(j == m)//all girls are over before boys
		return 1e12;//return very large which can never be anwer
	if(dp[i][j] != -1)
		return dp[i][j];
	int option1 = 0 + Valentine_Magic(i, j + 1);
	//option1 -> curret boy not choosing current girl
	int option2 = abs(a[i] - b[j]) + Valentine_Magic(i + 1, j + 1);
	//(i, j + 1) not possible as no. of boys are less
	return dp[i][j] = min(option1, option2);
}
int32_t main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < m; i++)
		cin >> b[i];
	memset(dp, -1 , sizeof(dp));
	sort(a, a + n);
	sort(b, b + m);
	int ans = Valentine_Magic(0, 0);
	cout << ans;
}