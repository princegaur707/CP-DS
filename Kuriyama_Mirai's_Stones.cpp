#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
	int n;
	cin >> n;
	int arr[n + 1];
	arr[0] = 0;
	int pre[n + 1];
	pre[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		pre[i] = pre[i - 1] + arr[i];
	}
	sort(arr, arr + n + 1);
	int pre1[n + 1];
	pre1[0] = 0;
	for(int i = 1; i <= n; i++)
		pre1[i] = pre1[i - 1] + arr[i];
	int m;
	cin >> m;
	int type[m], l[m], r[m];
	for(int i = 0; i < m; i++)
	{
		cin >> type[i] >> l[i] >> r[i];
		if(type[i] == 1)
			cout << pre[r[i]] - pre[l[i] - 1] << endl;
		else
		{	 
			cout << pre1[r[i]] - pre1[l[i] - 1] << endl;
		}
	}
}