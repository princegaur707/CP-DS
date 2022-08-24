#include<bits/stdc++.h>
using namespace std;
const int N = 105;
bitset<N>p;
vector<int>primes;
int Prime_Sieve()
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
	primes.push_back(2);
	for(int i = 3; i <= N; i +=2)
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
	}
	for(int i = 0; i < (b - a + 1); i++)
	{
		if(p1[i] == 0)
		{
			cout << i + a << " ";
		}
	}
}

int main()
{
	Prime_Sieve();
	cout << "Sieve Result --> \n";
	for(int i = 0; i < primes.size(); i++)
	{
		cout<< primes[i] << " ";
	}
	cout << endl <<endl;
	cout << "Segmented Sieve Result -->\n";
	Segmented_Sieve(100, 200);
}