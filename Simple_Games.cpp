#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int m;
	cin >> n >> m;
	if(n - m > m - 1)
	{
		cout << m + 1;
	}
	else if(n - m < m - 1)
	{
		cout << m - 1;
	}
	else
	{
		if(m - 1 != 0)
			cout << m - 1;
		else
			cout << m;
	}
}