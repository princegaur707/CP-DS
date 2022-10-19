#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
	int n; //total no. of songs
	int m; //no. of moments written
	cin >> n >> m;
	int c[n], t[n];
	for(int i = 0; i < n; i++)
	{
		cin >> c[i] >> t[i];
	}
	int prefix_array[n];
	prefix_array[0] = t[0] * c[0];
	int moments[m];
	for(int i = 0; i < m; i++)
	{
		cin >> moments[i];
	}
	for(int i = 1; i < n; i++)
	{
		prefix_array[i] = prefix_array[i - 1] + t[i] * c[i];
	}
	for(int i = 0; i < m; i++)
	{
		int start = 0;
		int end = n - 1;
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
		cout << end + 1 << endl;
	}
}