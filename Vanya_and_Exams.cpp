//https://codeforces.com/contest/492/problem/C
#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
	int n;
	int r;
	int avg;
	cin >> n >> r >> avg;
	std::vector<pair<int, int>>v;
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		int x;
		int y;
		cin >> x >> y;
		sum += x;
		v.push_back({y, x});
	}
	if(sum >= avg * n)
	{
		cout << "0";
		return 0;
	}
	sort(v.begin(), v.end());
	int cnt = 0;
	int i = 0;
	while(sum < avg * n)
	{
		
		int temp = min(avg * n - sum, r - v[i].second);
		cnt += temp * v[i].first;
		sum += temp;
		i++;
	}
	cout << cnt;
}
