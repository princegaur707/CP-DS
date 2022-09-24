#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int m;
	cin >> n >> m;
	int arr[n];
	int brr[m];
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for(int i = 0; i < m; i++)
	{
		cin >> brr[i];
	}
	sort(arr, arr + n);
	vector<int>ans;
	for(int i = 0; i < m; i++)
	{
		int count = -1;  //imp. to keep -1 as otherwise it can result into wrong answer
		int start = 0;
		int end = n - 1; //not n keep n-1 as last element is on (n-1)th position
		while(start <= end)
		{
			int mid = (start + end) / 2;
			if(arr[mid] > brr[i])
			{
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
				count = mid;
			}
		}
		ans.insert(ans.begin() + i, count + 1); //count+1 as no. elements will be pos+1 due to zero based indexing
	}
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
}