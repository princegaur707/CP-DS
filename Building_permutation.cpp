#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int s = 0;
	for(int i = 0; i < n; i++)
	{
		s += abs(i + 1 - arr[i]);
	}
	cout << s;
}