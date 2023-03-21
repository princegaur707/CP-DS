#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
int dp[100005];
int pre[100005];
int k;
int Total(int len) {
	 if(len == 0)//That means we have found a way to reach the last bucket that means we have found an answer or a way
		return 1;
	if(dp[len] != -1)
		return dp[len];
	int option1 = Total(len - 1);//Red flower at the current index:
	int option2 = 0;
	if(len >= k)
		option2 =	Total(len - k);//White flower at the current index: so go directly at len - k position
	return dp[len] = (option1 + option2) % mod;
}	
void Prefix_Sum() {
	memset(dp, -1, sizeof(dp));
	pre[0] = 0;
	for(int i = 1; i < 100005; i++)
		pre[i] = (pre[i - 1] + Total(i)) % mod;
}
int32_t main() {
	int t;
	cin >> t >> k;
	Prefix_Sum();
	while(t--) {
		int a, b;
		cin >> a >> b;
		cout << (pre[b] - pre[a - 1] + mod) % mod << endl;
	}
}