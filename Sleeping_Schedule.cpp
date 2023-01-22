#include<bits/stdc++.h>
using namespace std;
int n, h, l, r;//taking long long solving with dp
int a[100005];
int Schedule(int pos, int sleeping_hour)
{
	if(pos == n)
	{
		return 0;
	}
	int sleep_option1 = (sleeping_hour + a[pos]) % h;
	int sleep_option2 = (sleeping_hour + a[pos] -1) % h;

	int ans1 = 0, ans2 = 0;
	if(sleep_option1 >= l and sleep_option1 <= r)
	{
		ans1 = 1;//counting as good sleep
	}
	if(sleep_option2 >= l and sleep_option2 <= r)
	{
		ans2 = 1;
	}
	int option1 = Schedule(pos + 1, sleep_option1) + ans1;
	int option2 = Schedule(pos + 1, sleep_option2) + ans2;
	return max(option1, option2);
}
int main()
{
	cin >> n >> h >> l >> r;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << Schedule(0, 0);
	// position: at which position currently we are standing in array
	// sleeping time: at which time we are going to sleep either at
	// a[position] or a[position] - 1
}