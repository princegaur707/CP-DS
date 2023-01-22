//https://codeforces.com/problemset/problem/1324/E
#include<bits/stdc++.h>
using namespace std;
int n, h, l, r;
int a[100005];
int Schedule(int pos, int waking_hour)
{
	if(pos == n)
	{
		return 0;
	}
	int waking_hour1 = (a[pos] + waking_hour) % h;
	int waking_hour2 = (a[pos] - 1 + waking_hour) % h;

	int ans1 = 0, ans2 = 0;
	if(waking_hour1 >= l and waking_hour1 <= r)
		ans1 = 1;
	if(waking_hour2 >= l and waking_hour2 <= r)
		ans2 = 1;
	int option1 = Schedule(pos + 1, waking_hour1) + ans1;
	int option2 = Schedule(pos + 1, waking_hour2) + ans2;
	return max(option1, option2);
}
int main()
{
	cin >> n >> h >> l >> r;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	cout << Schedule(0, 0);
}