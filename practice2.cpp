#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10000005;
bitset<N>p;
vector<int>primes;
void Prime_Sieve()
{
	for(int i = 3; i * i <= N; i += 2)
	{
		if(p[i] == 0)
		{
			for(int j = i * i; j <= N; j += i)
			{
				p[j] = 1;
			}
		}
	}
}
int div_factorial(int a, int b)
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
	Prime_Sieve();
	int t;
	cin >> t;
	while(t--)
	{
		int a;
		int b;
		cin >> a >> b;
		int n = div_factorial(a, b);
		int cnt = 0;
		while(n != 1)
		{
			for(int i = 2; i <= n; i++)
			{
				if(n % i == 0)
				{
					cout << i << endl;
					n = n / i;
					cnt++;
					break;
				}
			}
		}
		cout << cnt << endl;
	}
}