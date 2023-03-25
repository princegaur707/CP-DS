#include<bits/stdc++.h>
using namespace std;
#define int long long 
double dp[101][101][101];
int r, s, p;
double RockWin(int r, int s, int p) {
	if(r == 0 or s == 0)
		return 0;
	if(p == 0)
		return 1;
	if(dp[r][s][p] > -1)//we cannot take == as we are dealing with double values
		return dp[r][s][p];
	double ans = 0;
	double total = (r * p) + (p * s) + (s * r);

	ans += ((r * p) / total) * RockWin(r - 1, s, p);
	ans += ((r * s) / total) * RockWin(r, s - 1, p);
	ans += ((p * s) / total) * RockWin(r, s, p - 1);

	return dp[r][s][p] = ans; 
}
double ScissorWin(int r, int s, int p) {
	if(s == 0 or p == 0)
		return 0;
	if(r == 0)
		return 1;
	if(dp[r][s][p] > -1)//we cannot take == as we are dealing with double values
		return dp[r][s][p];
	double ans = 0;
	double total = (r * p) + (p * s) + (s * r);

	ans += ((r * p) / total) * ScissorWin(r - 1, s, p);
	ans += ((r * s) / total) * ScissorWin(r, s - 1, p);
	ans += ((p * s) / total) * ScissorWin(r, s, p - 1);

	return dp[r][s][p] = ans; 
}
double PaperWin(int r, int s, int p) {
	if(p == 0 or r == 0)
		return 0;
	if(s == 0)
		return 1;
	if(dp[r][s][p] > -1)//we cannot take == as we are dealing with double values
		return dp[r][s][p];
	double ans = 0;
	double total = (r * p) + (p * s) + (s * r);

	ans += ((r * p) / total) * PaperWin(r - 1, s, p);
	ans += ((r * s) / total) * PaperWin(r, s - 1, p);
	ans += ((p * s) / total) * PaperWin(r, s, p - 1);

	return dp[r][s][p] = ans; 
}
int32_t main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> r >> s >> p;
		memset(dp, -1, sizeof(dp));
		cout << fixed << setprecision(9) << RockWin(r, s, p) << " ";
		memset(dp, -1, sizeof(dp));
		cout << fixed << setprecision(9) << ScissorWin(r, s, p) << " ";
		memset(dp, -1, sizeof(dp));
		cout << fixed << setprecision(9) << PaperWin(r, s, p) << " ";
		cout << endl;
	}
}