#include <bits/stdc++.h>
using namespace std;
long long n,m,sum;
int main(){
	cin>>n>>m;
	int a[n],b[m];
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<m;i++)cin>>b[i];
	sort(a,a+n);
	sort(b,b+m);
	int j=m-1,i=0;
	while(true){
		sum+=max(0,b[j]-a[i]);
		if(i==n-1||j==0)break;
		i++;j--;
	}
	cout<<sum;
}