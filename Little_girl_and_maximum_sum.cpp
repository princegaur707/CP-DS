//https://codeforces.com/problemset/problem/276/C
#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
	int n; //no. of elements in array
	int k; //no. of query
	cin >> n >> k;
	int arr[n];
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int prefix_sum[n + 1] = {0};
	int start[k];
	int end[k];
	for(int i = 0; i < k; i++)
	{
		cin >> start[i] >> end[i];
		prefix_sum[start[i] - 1]++;
		prefix_sum[end[i]]--;
	}
	for(int i = 1; i <= n; i++)
	{
		prefix_sum[i] += prefix_sum[i - 1]; 
	}
	sort(prefix_sum, prefix_sum + n);
	int s = 0;
	for(int i = 0; i < n; i++)
	{
		s += arr[i] * prefix_sum[i];
	}
	cout << s;
}
/*Concepts Used:
Frequency Array
Prefix Sum
*/