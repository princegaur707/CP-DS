#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
	int n;
	cin >> n;
	vector<int>arr;
	int cnt = 0;
	for(int i = 1; i <= 2 * n; i++)
	{
		int flag = 0;
		int match_count = 0;
		int mid = i;
		int team_count = mid;
		while(mid % 2 == 0)
		{
			flag++;
			mid = mid / 2;
			match_count += mid;
		}
		match_count += (mid * (mid - 1)) / 2;
		if(match_count == n)
		{
			arr.push_back(team_count);
		}
	}
	if(arr.size())
	{
		for(auto x : arr)
		{
			cout << x << endl;
		}
	}
	else
	{
		cout << "-1";
	}
}