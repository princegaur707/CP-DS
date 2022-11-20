#include<bits/stdc++.h>
using namespace std;
int Solve(int n, int p)
{
	if(p == 0)
		return 1;
	else
		return n * Solve(n, p - 1);
}
int main()
{
	int n;
	int p;
	cin >> n >> p;
	cout << Solve(n,p);
}