#include<bits/stdc++.h>
using namespace std;
int GCD(int a, int b)
{
	if(a == 0)
		return b;
	if(b == 0)
		return a;
	if(a == b)
		return a;
	if(a > b)
		return GCD(a - b, b);
	return GCD(a, b - a);
}
int main()
{
	int primes[11] = {2,3,5,7,11,13,17,19,23,29,31};
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int arr[n];
		for(int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		int cnt = 0;
		int freq[1000] = {0};
		for(int i = 0; i < n - 1; i++)
		{
			for(int j = i + 1; j < n; j++)
			{
				freq[GCD(arr[i], arr[j])]++;
			}
		}
		cnt += freq[1];
		for(int i = 2; i < 1000; i++)
		{
			if(freq[i] > 0)
				cnt++;
		}
		cout << cnt << endl;
		vector<int>brr;
		int i = 0;
		while(cnt > 1)
		{
			brr.push_back(primes[i]);
			i++;
			cnt--;
		}
		int more_requirement = n - brr.size();
		for(int i = 0; i < more_requirement; i++)
		{
			brr.push_back(1);
		}
		for(int i = 0; i < n; i++)
		{
			cout << brr[i] << " ";
		}
		cout << endl;
	}
}