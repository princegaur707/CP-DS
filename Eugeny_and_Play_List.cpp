#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
	int n; //total no. of songs
	int m; //no. of moments written
	cin >> n >> m;
	int prefix_array[n + 1];
	prefix_array[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		int c;
		int t;
		cin >> c >> t;
		prefix_array[i] = prefix_array[i - 1] + c * t;
	}
	int moments[m + 1];
	for(int i = 1; i <= m; i++)
	{
		cin >> moments[i];
	}
	for(int i = 1; i <= m; i++)
	{
		int start = 1;
		int end = n;
		while(start < end)
		{
			int mid = start + (end - start) / 2;
			if(moments[i] <= prefix_array[mid])
			{
				 end = mid;
			}
			else
			{
				start = mid + 1;
			}
		}
		cout << end << endl;
	}
}