#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int t;
	cin >> n >> t;
	int arr[n];
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	vector<int>freq;
	int s = 0;
	for(int i = 0; i < n; i++)
	{
		s += arr[i];
		freq.insert(freq.begin() + i, s);
	}
	for(int i = 0; i < n; i++)
	{
		freq[i] %= n;
		cout << freq[i] << " ";
	}
}