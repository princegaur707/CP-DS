#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int h;
	int k;
	int mn = INT_MAX;
	int ans;
	cin >> n >> k;
	int arr[n + 1];
	arr[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> h;
		arr[i] = arr[i-1] + h;
		if(i >= k && arr[i] - arr[i-k] < mn)
		{
			mn = arr[i] - arr[i - k];
			ans = i - k + 1;
		}
	}
	cout << ans;
}