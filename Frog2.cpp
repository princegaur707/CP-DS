// https://atcoder.jp/contests/dp/tasks/dp_b
#include<bits/stdc++.h>
using namespace std;
int Frog2(int *a, int pos, int k)
{
	if(pos <= 0)
	{
		return 0;
	}
	int ans = INT_MAX;
	for(int i = 1; i <= k; i++)
	{
		if(pos - i < 0)
			break;
		
		int value = Frog2(a, pos - i, k);
		ans = min(ans, abs(a[pos] - a[pos - i]) + value);
	
	}
	return ans;
}
int main()
{
	int n;
	int k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << Frog2(a, n - 1, k);
}