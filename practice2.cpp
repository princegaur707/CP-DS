#include<bits/stdc++.h>
using namespace std;
void Solve(int n)
{
	if(n == 0)
		return;
	cout << n << endl;
	Solve(n - 1);
	cout << n << endl;
}
int main()
{
	Solve(5);
}