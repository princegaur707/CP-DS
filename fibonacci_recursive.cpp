// Fibonacci Series using Recursion
#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
	if (n <= 1)
		return n;
	return fib(n - 1) + fib(n - 2); //we cannot directly print answer here as we are using return while in Solve
									//examples of recursion, we were not using return
}

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i <= n; i++)
		cout << fib(i) << endl;
}