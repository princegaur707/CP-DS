#include <bits/stdc++.h>
using namespace std;
long long n, m, sum;
int main()
{
	cin >> n >> m;
	int arr[n];
	int brr[m];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	for(int i = 0; i < m; i++)
		cin >> brr[i];
	sort(arr, arr + n);
	sort(brr, brr + m);
	int j = m - 1;
	int i = 0;
	while(true)
	{
		sum += max(0, brr[j] - arr[i]);
		if(i == n - 1 || j == 0)
			break;
		i++;
		j--;
	}
	cout<<sum;
}