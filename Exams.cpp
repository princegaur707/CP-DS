#include<iostream>
#include<stdio.h>
using namespace std;
int a[100010],b[100010],v[100010];
int main()
{
	int n,m,i;
	cin>>n>>m;
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	long long Min=0;
	for (i=1;i<=m;i++) 
	{
		scanf("%d",&b[i]);
		Min+=b[i];
	}
	cout << Min;
	if (Min>n)
	{
		cout<<-1;
		return 0;
	}
	int l=Min+m,r=n;
	while (l<=r)
	{
		int mid=(l+r)/2;
		for (i=1;i<=n;i++) v[i]=0;
		int s=0;
		for (i=mid;i>0;i--)
		{
			if (a[i]&&!v[a[i]]&&i>b[a[i]]) 
			{
				v[a[i]]=1;
				s++;
			}
		}
		if (s==m) r=mid-1;
		else l=mid+1;
	}
	if (r==n) cout<<-1;
	else cout<<r+1;
	return 0;
}