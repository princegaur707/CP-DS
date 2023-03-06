#include<bits/stdc++.h>
using namespace std;
int dp[10005];
int fib(int n) {
	if (n <= 1)
		return n;

	if (dp[n] != -1)//if dp[n] is not -1 it means we initialized it
		return dp[n];

	int option1 = fib(n - 1);
	int option2 = fib(n - 2);

	return dp[n] = option1 + option2;
}
int main() {
	int n;
	cin >> n;
	memset(dp, -1, sizeof(dp));//initialization of dp array
	cout << fib(n) << endl;
}
