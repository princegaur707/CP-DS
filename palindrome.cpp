#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int a[n];
		int b[n];
		for(int i = 1; i < n; i++)
		{
			b[i] = 1;
		}
		b[n] = 2;
		for(int i = 1; i <= n; i++)
		{
			char x;
			cin >> x;
			a[i] = '9' - x;
		}
		if(a[1] != 0)
		{
			for(int i = 1; i <= n; i++)
			{
				cout << a[i];
			}
		}
		else
		{
			for(int i = 1; i <= n; i++)
			{
				a[i] = b[i] + a[i];
				if(a[i] >= 10)
				{
					a[i] -= 10;
					a[i - 1]++;
				}
			}
			for(int i = 1; i <= n; i++)
			{
				cout << a[i];
			}
		}
		cout << endl;
	}
}