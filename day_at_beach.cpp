//https://codeforces.com/problemset/problem/599/C
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int left_max[n + 1];//we will need these to be size of 
	int right_min[n + 1];//n+1
	left_max[0] = INT_MIN;
	for(int i = 1; i <= n; i++)
	{
		left_max[i] = max(left_max[i - 1], arr[i - 1]);
	}
	right_min[n] = INT_MAX;
	for(int i = n - 1; i >= 0; i--)
	{
		right_min[i] = min(right_min[i + 1], arr[i]);
	}
	int blocks = 1;
	for(int i = 1; i < n; i++)
	{
		if(left_max[i] <= right_min[i])
		{
			blocks++;
		}
	}
	cout << blocks;
}
