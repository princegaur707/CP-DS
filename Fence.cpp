#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int k;
	int arr[n];
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int sum = 0;
	for(int i = 0; i < k; i++)
	{
		sum += arr[i];
	}
	int min = sum;
	for(int i = k; i < n; i++)
	{
		sum -= i - k;
		sum += arr[k];
		if(min > sum)
		{
			min = sum;
		}
	}
	cout << min;
}