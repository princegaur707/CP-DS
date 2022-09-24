//https://hack.codingblocks.com/app/contests/3317/1065/problem
#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n];
		int freq[100005] = {0};
		int sum = 0;
		freq[0] = 1; //Explained below
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			sum += a[i];
			sum = sum % n;
			sum = (sum + n) % n;
			freq[sum]++;
		}
		int ans = 0;
		for(int i = 0; i < n; i++)
		{	
			int value = freq[i];
			ans += (value * (value - 1)) / 2;
		}
		cout << ans << endl;
	}
}
/*
for			   [5,7,7,7,7] 		n = 5
prefix array : [5,12,19,26,33]
pre[] % n 	 : [0,2,4,1,3] so according to nC2 formula there is no good subarray
but we can see '5' is good subarray so tackle this situation we add freq[0]=1