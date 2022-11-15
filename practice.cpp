#include<bits/stdc++.h>
using namespace std;
const int N = 1e7;
bitset<N>primes;
long long freq[N];
int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		int x;
		cin >> x;
		freq[x]++;
	}
	for(int i = 2; i <= N; i++)
	{
		if(!primes[i])
		{
			for(int j = 2 * i; j <= N; j += i)
			{
				freq[i] += freq[j];
				primes[j] = 1;
			}
		}
	}
	for(int i = 0; i < 100; i++)
		cout << freq[i] << " ";
	cout << endl;
	for(int i = 0; i < 100; i++)
		cout << primes[i] << " ";
	cout << endl;
	for(int i = 1; i <= N; i++)
	{
		freq[i] += freq[i - 1];
	}
	int m;
	cin >> m;
	while(m--)
	{
		int l;
		int r;
		cin >> l >> r;
		l = min(N, l);
		r = min(N, r);
		cout << freq[r] - freq[l - 1] << endl;
	}
}