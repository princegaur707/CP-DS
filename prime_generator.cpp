#include<bits/stdc++.h>
using namespace std;
const int N = 10000005;
bitset<N>p;
vector<int>primes;
void Prime_Sieve()
{
	for(int i = 3; i * i < N; i += 2)
	{
		if(p[i] == 0)
		{
			for(int j = i * i; j <= N; j += i)
			{
				p[j] = 1;
			}
		}
	}
	primes.push_back(2);
	for(int i = 3; i <= N; i += 2)
	{
		if(p[i] == 0)
		{
			primes.push_back(i);
		}
	}
}
void Segmented_Sieve(int a, int b)
{
	bool p1[b - a + 1] = {0};
	for(int i = 0; primes[i] * primes[i] <= b; i++)
	{
		int start = (a / primes[i]) * primes[i];
		if(start < a)
		{
			start = start + primes[i];
		}
		for(int j = start; j <= b; j+=primes[i])
		{
			p1[j - a] = 1;
		}
		if(start == primes[i])
		{
			p1[start - a] = 0;
		}
	}
	for(int j = a; j <= b; j++)
	{
		if(p1[j - a] == 0)
		{
			cout << j << endl;
		}
	}
}

int main()
{
	int t;
	cin >> t;
	Prime_Sieve();
	while(t--)
	{
		int m , n;
		cin >> m >> n;
		if(m == 1)
		{
			m++;
		}
		Segmented_Sieve(m, n);
		cout << endl;
	}
}