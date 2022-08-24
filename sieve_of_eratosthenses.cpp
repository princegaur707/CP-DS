#include<bits/stdc++.h>
using namespace std;
//bool p[10005] = {0}; //global array greater than 10^8 will lead to issue
					//wasting lots of space so we will not use bitset.

// bool will consume 10^8*8 while bitset will consume 10^8.
bitset<10000>p; //makes same work 8 times faster
void sieve_of_eratosthenses(int n)
{
	for(int i = 3; i * i <= n; i += 2)
	{
		if(p[i] == 0)
		{
			for(int j = i * i; j <= n; j += i)
			{
				p[j] = 1;
			}
		}
	}
	cout << "2 ";
	for(int i = 3; i <= n; i+=2)
	{
		if(p[i] == 0)
		{
			cout << i << " ";
		}
	}
}
int main()
{
	int n;
	cin >> n;
	sieve_of_eratosthenses(n);
}