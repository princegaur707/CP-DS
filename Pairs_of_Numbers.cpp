#include<bits/stdc++.h>
using namespace std;
int ans = INT_MAX;

void Function(int a, int b, int count)
{
	if(a == 1 and b == 1)
	{
		ans = min(count, ans);
	}
	if(a - b > 0)
	{
		Function(a - b, b, count + 1);
	}
	if(b - a > 0)
	{
		Function(a, b - a, count + 1);
	}
}
void Pair(int n)
{
	if(n == 1)//0 steps needed to make 1 one.
	{
		cout << 0 << endl;
		return;
	}

	for(int x = 1; x < n; x++)
	{
		Function(x, n - x, 1);
	}
	cout << ans;	
}
int main()
{
	int n;
	cin >> n;
	Pair(n);
}