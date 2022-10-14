#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100007],ans,temp;
int n;
map<ll,ll> m1,m2;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		m1[a[i]]++;
		ans+=a[i];
	}
	cout << ans << endl;
	if (ans%2==1) {cout<<"NO";return 0;}
	ans/=2;
	temp=0;
	for (int i=1;i<=n;i++)
	{
		cout << i << " ";
		temp+=a[i];
		m1[a[i]]--;
		m2[a[i]]++;
		if (temp==ans) {cout << i <<"1YES";return 0;}
		if (m1[ans-temp]) {cout << i <<"2YES";return 0;}
		if (m2[temp-ans]) {cout << i <<"3YES";return 0;}
	}
	cout<<"NO";
}