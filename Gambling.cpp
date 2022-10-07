#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
	int n;
	cin >> n;
	int arr[n + 1];
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	arr[n] = 0;
	sort(arr, arr + n, greater<int>());
	int brr[n + 1];
	brr[n] = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> brr[i];
	}
	sort(brr, brr + n, greater<int>());
	int ans1 = 0;
	int ans2 = 0;
	int i = 0;
	int j = 0;
	while(i < n or j < n)
	{
		if(arr[i] > brr[j])
		{
			ans1 += arr[i];
			i++;
		}
		else
		{
			j++;
		}
		if(brr[j] > arr[i])
		{
			ans2 += brr[j];
			j++;
		}
		else
		{
			i++;
		}
	}
	cout << ans1 - ans2;
}