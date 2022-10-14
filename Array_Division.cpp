#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int arr[n];
	int sum = 0;
	unordered_map<int,int>m1;
	unordered_map<int,int>m2;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
		m1[arr[i]]++;
	}
	if(sum % 2 == 1) //Two equal sums are only possible when the total sum is even
	{
		cout << "NO";
		return 0;
	}
	sum = sum / 2;
	int running_sum = 0;
	for(int i = 0; i < n; i++)
	{
		running_sum += arr[i];
		m1[arr[i]]--;
		m2[arr[i]]++;
		if(sum == running_sum or m1[sum - running_sum] or m2[running_sum - sum])
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}