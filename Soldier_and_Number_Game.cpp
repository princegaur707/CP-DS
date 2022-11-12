#include<bits/stdc++.h>
using namespace std;
#define int long long
int factorialshort(int a, int b)
{
	int ans = 1;
	while(a > b)
	{
		ans *= a;
		a--;
	}
	return ans;
}
int32_t main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int a;
		int b;
		cin >> a >> b;
		int n = factorialshort(a, b);
		int cnt = 0;
		while(n > 1)
		{
			cout << n << endl;
			for(int i = 2; i <= n; i++)
			{
				if(n % i == 0)
				{
					n = n / i;
					cnt++;
					break;
				}
			}
		}
		cout << cnt << endl;
	}
}
/*TEST CASE:
1
5000000 4999995
OUTPUT: 13 EXPECTED : 23
*/