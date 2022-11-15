
#include<cstdio>
#include<cstring>
typedef __int64 ll;
const int N = 10000005;
bool p[N];
ll cnt[N];
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		int v;
		scanf("%d",&v);
		cnt[v]++;
	}
	for(i=2;i<N;i++)if(!p[i])
	{
		for(j=2*i;j<N;j+=i)
		{
			cnt[i]+=cnt[j];
			p[j]=true;
		}
	}
	for(int i = 0; i < 100; i++)
		printf(p[i]);
	printf("\n");
	for(i=2;i<N;i++)
	{
		if(p[i])cnt[i]=cnt[i-1];
		else cnt[i]+=cnt[i-1];
	}
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(l>=N){puts("0");continue;}
		if(r>=N)r=N-1;
		printf("%I64d\n",cnt[r]-cnt[l-1]);
	}
	return 0;
}