//https://hack.codingblocks.com/app/contests/3317/300/problem
#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
	int n; //no. of students 
	int m; //no. of coupons
	int x; //no. of coupons required for 100% off
	int y;//additional coupons we can get
	cin >> n >> m >> x >> y;
	int temp;
	int left = 0;
	int right = n;
	int ans = -1;
	while(left <= right)
	{
		int mid = (left + right) / 2;
		if(mid * x == ((n - mid) * y + m))
		{
			ans = mid;
			break;
		}
		else if(mid * x > (((n - mid) * y) + m))
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
			ans = mid;
		}
	}
	cout << ans;
}