#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int start = 0;
	int end = 5 * n;
	vector<int>arr;
	while(start < end)
	{
		int match_count = 0;
		int mid = (start + end) / 2;
		int team_count = mid;
		while(mid % 2 == 0)
		{
			mid = mid / 2;
			match_count += mid;
		}
		match_count += (mid * (mid - 1)) / 2;
		cout << match_count << endl;
		if(match_count == n)
		{
			arr.push_back(team_count);
			end = team_count + 1;
		}
		else if(match_count > n)
		{
			end = team_count - 1;
		}
		else
		{
			start = team_count;
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