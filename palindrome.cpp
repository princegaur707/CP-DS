//https://codeforces.com/problemset/problem/1700/B
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
			int b[n];
			for(int i = 1; i < n; i++)
			{
				b[i] = 1;
			}
			b[n] = 2;
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
/*
We cannot make the number directly for ex. of upto 10,000,00 length as it will out of range for even int long long 
so we need to deal this condition with array length.
Intution:
we will get the the difference between nearest '999..n times' series with the help of '9' - ch but if in case
we get the a[0] to be zero that implies there is 9 present at the first position of number and now we neeed
to make this number of '1111..n+1' series for this we need to add '1111..(n -1) times 2' 
We are firstly trying to make no. of 9999.. series if not possible then of subsequent 111... series but
not of 100...1 because this do not guarantee to make required no. of length n.
*/