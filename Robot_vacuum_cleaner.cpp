#include<bits/stdc++.h>
using namespace std;
#define int long long
int Count(string s)
{
	int cnt = 0;
	int ans = 0;
	for(auto x : s)
	{
		if(x == 's')
		{
			cnt++;
		}
		else
		{
			ans += cnt;
		}
	}
	return ans;
}
bool Compare(string a, string b)
{
	return Count(a + b) > Count(b + a);
}
int32_t main()
{
	int n;
	cin >> n;
	string str[n];
	for(int i = 0; i < n; i++)
	{
		cin >> str[i];
	}
	sort(str, str + n, Compare);
	string final;
	for(int i = 0; i < n; i++)
	{
		final += str[i];
	}
	cout << Count(final);
}