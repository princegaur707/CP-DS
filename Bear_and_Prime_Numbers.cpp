#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7 + 200;
bitset<N>primes;
void findprimes(long n)
{
	for(int i = 2; i <= n; i += 2)
	{
		primes[i] = 1;
	}
	primes[0] = 1;
	primes[1] = 1;
	primes[2] = 1;
	for(int i = 3; i * i <= n ; i += 2)
	{
		if(primes[i] == 0)
		{
			for(int j = i * i; j <= n; j += i)
			{
				primes[j] = 1;
			}
		}
	}
}
int32_t main()
{
	int n;
	cin >> n;
	int maxi = -1;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		maxi = max(maxi, arr[i]);
	}
	findprimes(maxi);
	for(int i = 0; i <= maxi; i++)
	{
		if(primes[i] == 0)
		{
			cout << i << " ";
		}
	}
}