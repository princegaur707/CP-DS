#include<bits/stdc++.h>
using namespace std;
#define int long long
int k;
int sum[1000002];
string a;
int Solve() {
	int s = 0;
	int ans = 0;
	sum[0] = 1;
	for(int i = 0; i < a.length(); i++) {
		s += a[i] - '0';
		if(s >= k)
			ans += sum[s - k];
		sum[s]++;
		// for(int i = 0; i < 10; i++) 
		// 	cout << sum[i] << " ";
		// cout << endl << ans;
		// cout << endl;
	}
	return ans;
}
int32_t main() {
	cin >> k >> a;
	cout << Solve();
}