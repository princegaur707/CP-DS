#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n; //no. of customers
		int m; //initial temp. of restaurant
		cin >> n >> m;
		int t[n];
		int l[n];
		int h[n];
		for(int i = 0; i < n; i++)
		{
			cin >> t[i] >> l[i] >> h[i];
		}
		int current_temp = m;
		int flag = 0;
		int range[2];
		range[0] = m;
		range[1] = m;
		for(int i = 0; i < n; i++)
		{
			cout << "range: " << range[0] << " " << range[1] << endl;	
			if(l[i] >= range[0] - t[i] and h[i] <= range[1] + t[i])
			{
				cout << "1" << endl;
				range[0] = max(l[i], range[0] - t[i]);
				range[1] = min(h[i], range[1] + t[i]);
			}
			else
			{
				cout << "2" << endl;
				cout << "NO" << endl;
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			cout << "YES" << endl;
		}
	}
}