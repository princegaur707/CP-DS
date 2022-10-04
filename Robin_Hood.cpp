#include<bits/stdc++.h>
using namespace std;
long long n,k,l,r,mid,ans,num; 
long long a[500005],sum,mx=-1e9,mi=1e9;
int check1(long long x)
{
	long long cnt=0;
	for(int i=1;i<=n;i++)if(a[i]>x)cnt+=(a[i]-x);
	return cnt<=k;
}
int check2(long long x)
{
	long long cnt=0;
	for(int i=1;i<=n;i++)if(a[i]<x)cnt+=(x-a[i]); 
	return cnt<=k;
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		mi=min(mi,a[i]);
		mx=max(mx,a[i]);
		sum+=a[i]; 
	}
	l=(sum+n-1)/n; //why +n is done here
	r=mx;
	while(l<=r)
	{
		mid=(l+((r-l)>>1));
		cout << endl << "mid : " << mid << endl;
		if(check1(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	l=mi;
	r=sum/n;
	while(l<=r)
	{
		mid=(l+((r-l)>>1)); 
		if(check2(mid))
		{
			num=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans-num;
	return 0;
}