//I have understood how they are going after the patterns such as For 2 --> 4, 6, 8, 10. For n -> 2*n, 3n,4n,5n...
//but unable to understand if there is any impact of this on time complexity and if there is 
//now what is TC as earlier it was O(m * n). correct answer below
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7 + 500;
bitset<N>primes;
void findprimes(long n)
{
	primes[0] = 1;
	primes[1] = 1;
	for(int i = 4; i <= n; i += 2)
	{
		primes[i] = 1;
	}
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
	int pre[maxi + 1] = {0};
	for(int i = 0; i <= maxi; i++)
	{
		if(primes[i] == 0)
		{
			for(int j = 0; j < n; j++)
			{
				if(arr[j] % i == 0)
					pre[i]++;
			}
		}			
	}
	for(int i = 1; i <= maxi; i++)
		pre[i] += pre[i - 1];
	int m;
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		int l;
		int r;
		cin >> l >> r;	
		r = min(r, maxi);
		if(l > maxi)
		{
			l = r + 1;
		}
		cout << pre[r] - pre[l - 1] << endl;
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