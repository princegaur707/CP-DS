#include<bits/stdc++.h>
using namespace std;
const int N = 10000005;
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
	for(int i = 2; i < N; i++)
	{
		if(!primes[i])
		{
			for(int j = 2 * i; j < N; j += i)
			{
				freq[i] += freq[j];
				primes[j] = 1;
			}
		}
	}
	for(int i = 2; i < N; i++)
	{
		if(!primes[i])
			freq[i] += freq[i - 1];
		else
			freq[i] = freq[i - 1];
	}
	int m;
	cin >> m;
	while(m--)
	{
		int l;
		int r;
		cin >> l >> r;
		if(l >= N)
		{
			cout << "0" << endl;
			continue;
		}
		if(r >= N)
			r = N - 1;
		cout << freq[r] - freq[l - 1] << endl;
	}
}

// #include<cstdio>
// #include<cstring>
// typedef __int64 ll;
// const int N = 10000005;
// bool p[N];
// ll cnt[N];
// int main()
// {
// 	int n,i,j;
// 	scanf("%d",&n);
// 	for(i=1;i<=n;i++)
// 	{
// 		int v;
// 		scanf("%d",&v);
// 		cnt[v]++;
// 	}
// 	for(i=2;i<N;i++)if(!p[i])
// 	{
// 		for(j=2*i;j<N;j+=i)
// 		{
// 			cnt[i]+=cnt[j];
// 			p[j]=true;
// 		}
// 	}
// 	for(i=2;i<N;i++)
// 	{
// 		if(p[i])cnt[i]=cnt[i-1];
// 		else cnt[i]+=cnt[i-1];
// 	}
// 	int m;
// 	scanf("%d",&m);
// 	while(m--)
// 	{
// 		int l,r;
// 		scanf("%d%d",&l,&r);
// 		if(l>=N){puts("0");continue;}
// 		if(r>=N)r=N-1;
// 		printf("%I64d\n",cnt[r]-cnt[l-1]);
// 	}
// 	return 0;
// }