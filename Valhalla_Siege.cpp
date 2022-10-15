#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
	int n; //no. of warriors
	int q; //no. of minutes in battle
	cin >> n >> q;
	int arr[n + 1];
	arr[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		arr[i] = arr[i - 1] + x;
	}
	int brr[q + 1];
	brr[0] = 0;
	for(int i = 1; i <=  q; i++)
	{
		int y;
		cin >> y;
		brr[i] = brr[i - 1] + y;
	}
	int pivot = 0;
	for(int i = 1; i <= q; i++)
	{
		int start = 1;
		int end = n;
		int ans = 0;
		while(start <= end)
		{
			int mid = (start + end) / 2;
			if(arr[mid] > brr[i] - brr[pivot])
			{
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
				ans = mid;
			}
		}
		if (ans == n)
		{
			pivot = i;
			ans = 0;
		}
		cout << n - ans << endl;
	}
}