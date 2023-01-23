//Not choosing the matching ratio method
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
int *a, *b; //taking dynamic arrays

int Solve(int pos, int sum){
	if(pos == n)
	{
		if(sum == 0)
			return 0;
		return -1e12;
	}
	int option1 = a[pos] + Solve(pos + 1, sum + a[pos] - k * b[pos]); 
	int option2 = 0 + Solve(pos + 1, sum);
	return max(option1, option2);
}
int32_t main(){
	cin >> n >> k;
	a = new int[n];
	b = new int[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}
	int ans = Solve(0, 0);
	if(ans <= 0)
	{
		cout << "-1";
	}
	else
	{
		cout << ans;
	}
}